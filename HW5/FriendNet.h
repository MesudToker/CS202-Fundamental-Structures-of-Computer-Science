//Ömer Mesud TOKER
// 21302479
// Section 1

#ifndef FRIENDNET_H
#define FRIENDNET_H

#include <iostream>
#include <string>
using namespace std;

enum VertexState { White, Gray, Black };

class Person{
private:
	string name;
	VertexState state;
	int num_friend;
	int id;
	int dist;

	friend class FriendNet;
};

class FriendNet{
public:
	FriendNet(const string fname);
	FriendNet(const FriendNet& aNet);   // copy contructor
	~FriendNet();      // destructor

	void listFriends(const string pname);
	void listPeople(const string pname, const int hno);

	void displayAverageDegrees();
	void displayAverageClusteringCoefficients();
	void displayDiameters();

	//void print_list();
	Person* get_by_name(string name);

	// ...
	// define other public member functions here,
	// if you have any
private:
	bool ** adj_matrix;
	Person* person_list;
	int person_count;

	void get_person_from_line(ifstream inp_file, string line);
	void breadth_first(Person* p, int hop_num);
	int breadth_first_degree(Person* p, int& num_node);
	void unmark_persons();
	double get_clustering_coefficient(Person* p);
	double breadth_first_cc(Person* p, int& num_node);
	int get_max_shortest_path(Person* p1);
	int get_max_shortest_of_comp(Person* p1);
	Person* get_min_dist_person(Person* p);
	int get_comp_count();
	// ...
	// define your data members here
	// define private member functions here, if you have any
};
#endif
