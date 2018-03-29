//Ömer Mesud TOKER
// 21302479
// Section 1

#include "FriendNet.h"
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<queue>

using namespace std;

FriendNet::FriendNet(const string fname){
	ifstream inp_file;
	inp_file.open((fname + ".txt").c_str());
	string line;

	if (inp_file.is_open()){
		getline(inp_file, line);
		this->person_count = atoi(line.c_str());

		//cout << "\n person count " << person_count;

		adj_matrix = new bool*[person_count];

		this->person_list = new Person[person_count];

		for (int i = 0; i < person_count; i++){
			adj_matrix[i] = new bool[person_count];
			for (int j = 0; j < person_count; j++){
				adj_matrix[i][j] = false;
			}
		}

		int id, num_friend;
		string name;
		int count = 0;

		while (inp_file >> id >> name >> num_friend){
			int id_friend;
			for (int i = 0; i < num_friend; i++){
				inp_file >> id_friend;
				adj_matrix[count][id_friend] = true;
			}

			person_list[count].id = id;
			person_list[count].name = name;
			person_list[count].state = White;

			person_list[count].num_friend = num_friend;

			count++;
		}
	}

	inp_file.close();
}

//void FriendNet::print_list(){
//	cout << "\n -----------------------beginning of the list-----------------------\n";
//
//	for (int i = 0; i < this->person_count; i++){
//		cout << this->person_list[i].id << " " << this->person_list[i].name << " " << this->person_list[i].num_friend << endl;
//	}
//
//	cout << "\n -----------------------end of the list-----------------------\n";
//}

FriendNet::FriendNet(const FriendNet& aNet){
}

FriendNet::~FriendNet(){
}

Person* FriendNet::get_by_name(string name){
	for (int i = 0; i < this->person_count; i++){
		if (this->person_list[i].name == name){
			return this->person_list + i;
		}
	}

	return NULL;
}

void FriendNet::listFriends(const string pname){
	Person* p = get_by_name(pname);
	if (p == NULL){
		cout << endl << pname << " does not exist in the network";
		return;
	}

	int id = p->id;
	int num_f = p->num_friend;

	if (num_f == 0){
		cout << endl << pname << " does not have any friend";
	}
	else{
		cout << endl << pname << " has " << num_f << " friends: ";
	}

	for (int i = 0; i < this->person_count; i++){
		if (this->adj_matrix[id][i]){
			cout << this->person_list[i].name;
			if (i != person_count - 1){
				cout << ", ";
			}
		}
	}
}

void FriendNet::listPeople(const string pname, const int hno){
	Person* p = get_by_name(pname);
	if (p == NULL){
		cout << endl << pname << " does not exist in the network";
		return;
	}

	if (hno <= 0){
		cout << endl << hno << " is not a valid hop number";
		return;
	}

	//int id = p->id;

	breadth_first(p, hno);
}

void FriendNet::breadth_first(Person* p, int hop_num){
	queue<Person*> que;
	que.push(p);
	p->state = Gray;

	int* persons = new int[this->person_count];
	int count = 0;
	int num_person = 0;

	while (!que.empty() && count <= hop_num + 1){
		Person* curr_per = que.front();
		int curr_id = curr_per->id;

		que.pop();

		for (int i = 0; i < this->person_count; i++){
			if (this->adj_matrix[curr_id][i]){
				if (this->person_list[i].state == White){
					this->person_list[i].state = Gray;
					persons[num_person] = i;
					que.push(person_list + i);
					num_person++;
				}
			}
		}
		count++;
	}

	if (num_person == 0){
		cout << endl << "Cannot access to any people from " << p->name;
	}
	else{
		cout << endl << "People accessible from " << p->name << " within " << hop_num << " hops: ";

		for (int i = 0; i < num_person; i++){
			cout << person_list[persons[i]].name;
			if (i != num_person - 1){
				cout << ", ";
			}
		}
	}

	unmark_persons();

	persons = NULL;
	delete[] persons;
}

void FriendNet::unmark_persons(){
	for (int a = 0; a < this->person_count; a++){
		this->person_list[a].state = White;
	}
}

int FriendNet::breadth_first_degree(Person* p, int& num_node){
	queue<Person*> que;
	que.push(p);
	p->state = Gray;
	int tot_degree = p->num_friend;
	num_node = 1;

	while (!que.empty()){
		Person* curr_per = que.front();
		int curr_id = curr_per->id;

		que.pop();

		for (int i = 0; i < this->person_count; i++){
			if (this->adj_matrix[curr_id][i]){
				if (this->person_list[i].state == White){
					this->person_list[i].state = Gray;
					que.push(person_list + i);
					num_node++;
					tot_degree += person_list[i].num_friend;
				}
			}
		}
	}

	return tot_degree;
}

double FriendNet::breadth_first_cc(Person* p, int& num_node){
	queue<Person*> que;
	que.push(p);
	p->state = Gray;
	double tot_cc = get_clustering_coefficient(p);
	num_node = 1;

	while (!que.empty()){
		Person* curr_per = que.front();
		int curr_id = curr_per->id;

		que.pop();

		for (int i = 0; i < this->person_count; i++){
			if (this->adj_matrix[curr_id][i]){
				if (this->person_list[i].state == White){
					this->person_list[i].state = Gray;
					que.push(person_list + i);
					num_node++;
					tot_cc += get_clustering_coefficient(person_list + i);
				}
			}
		}
	}

	return tot_cc;
}

void FriendNet::displayAverageDegrees(){
	int comp_num = 0;
	int* degrees = new int[this->person_count];
	int* num_node = new int[this->person_count];

	for (int i = 0; i < this->person_count; i++){
		if (this->person_list[i].state == White){
			degrees[comp_num] = breadth_first_degree(&(person_list[i]), (num_node[comp_num]));
			comp_num++;
		}
	}

	cout << endl << "There are " << comp_num << " connected components. The average degrees are: ";

	for (int i = 0; i < comp_num; i++){
		cout << endl << "For component " << (i + 1) << " :" << degrees[i] * 1.0 / num_node[i];
	}

	unmark_persons();

	degrees = NULL; num_node = NULL;
	delete[]degrees;  delete[]num_node;
}

int FriendNet::get_comp_count(){
	int comp_num = 0;
	int* degrees = new int[this->person_count];
	int* num_node = new int[this->person_count];

	for (int i = 0; i < this->person_count; i++){
		if (this->person_list[i].state == White){
			degrees[comp_num] = breadth_first_degree(&(person_list[i]), (num_node[comp_num]));
			comp_num++;
		}
	}

	unmark_persons();

	degrees = NULL; num_node = NULL;
	delete[]degrees;  delete[]num_node;

	return comp_num;
}

void FriendNet::displayAverageClusteringCoefficients(){
	int comp_num = 0;
	double* clusterings = new double[this->person_count];
	int* num_node = new int[this->person_count];

	//cout << "\n1";

	for (int i = 0; i < this->person_count; i++){
		if (this->person_list[i].state == White){
			clusterings[comp_num] = breadth_first_cc(&(person_list[i]), (num_node[comp_num]));
			comp_num++;
		}
	}

	cout << endl << "There are " << comp_num << " connected components. The average clustering coefficients are: ";

	for (int i = 0; i < comp_num; i++){
		cout << endl << "For component " << (i + 1) << " :" << clusterings[i] * 1.0 / num_node[i];
	}

	//cout << "\n2";

	unmark_persons();

	clusterings = NULL; num_node = NULL;
	delete[]num_node; delete[]clusterings;
}

double FriendNet::get_clustering_coefficient(Person* p){
	int d = p->num_friend;

	if (d == 0 || d == 1){
		return 0;
	}

	int id = p->id;
	int edges = 0;
	int count = 0;
	int* friends = new int[this->person_count];

	for (int i = 0; i < this->person_count; i++){
		if (this->adj_matrix[id][i]){
			friends[count] = i;
			count++;
		}
	}

	for (int i = 0; i < d; i++){
		for (int j = 0; j < d; j++){
			if (this->adj_matrix[friends[i]][friends[j]] && i != j){
				edges++;
			}
		}
	}

	friends = NULL;
	delete[] friends;

	return (edges / (d * (d - 1) * 1.0));
}

//Dijkstra's algorithm
int FriendNet::get_max_shortest_path(Person* p1){
	Person* curr_comp = new Person[this->person_count];

	for (int i = 0; i < this->person_count; i++){
		this->person_list[i].dist = this->person_count; //longest dist will be n-1 in connected comp
	}
	p1->dist = 0;
	Person* curr = p1;

	for (int i = 0; i < this->person_count; i++){
		curr = get_min_dist_person(curr);
		curr_comp[i] = *(curr);

		curr->state = Black;

		for (int j = 0; j < person_count; j++){
			if (this->adj_matrix[curr->id][j] && this->person_list[j].state == White){
				int new_dist = curr->dist + 1;
				if (new_dist < person_list[j].dist){
					person_list[j].dist = new_dist;
				}
			}
		}
	}

	int max = 0;
	for (int i = 0; i < person_count; i++){
		if (curr_comp[i].dist > max && curr_comp[i].dist != 20){
			max = curr_comp[i].dist;
		}
	}

	curr_comp = NULL;
	delete[] curr_comp;

	return max;
}

int FriendNet::get_max_shortest_of_comp(Person* p1){
	int max = 0;
	int* comp_ids = new int[this->person_count];
	int comp_count = 0;

	unmark_persons();
	max = get_max_shortest_path(p1);

	//construct the component
	for (int i = 0; i < this->person_count; i++){
		if (this->person_list[i].state != White){
			comp_ids[comp_count] = i;
			comp_count++;
		}
	}

	for (int i = 0; i < comp_count; i++){
		unmark_persons();
		int new_num = get_max_shortest_path(&(person_list[comp_ids[i]]));

		if (new_num > max){
			max = new_num;
		}
	}

	comp_ids = NULL; delete[] comp_ids;
	return max;
}

Person* FriendNet::get_min_dist_person(Person* p){
	int min = this->person_count;
	int min_index = p->id;

	int i = 0;

	for (i = 0; i < this->person_count; i++){
		if (this->person_list[i].state == White && this->person_list[i].dist < min){
			min = person_list[i].dist;
			min_index = i;
		}
	}

	return (this->person_list + min_index);
}

void FriendNet::displayDiameters(){
	int comp_num = 0;
	int* diameters = new int[person_count];

	int comp_count = get_comp_count();

	for (int i = 0; i < this->person_count; i++){
		if (this->person_list[i].state == White && comp_num < comp_count){
			diameters[comp_num] = get_max_shortest_of_comp(&(person_list[i]));
			comp_num++;
		}
	}

	cout << endl << "There are " << comp_num << " connected components. The diameters are: ";

	for (int i = 0; i < comp_num; i++){
		cout << endl << "For component " << (i + 1) << " :" << diameters[i];
	}

	unmark_persons();
	diameters = NULL;
	delete[] diameters;
}
