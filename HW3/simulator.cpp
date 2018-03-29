// Ömer Mesud TOKER
// 21302479

#include "simulator.h"

// ctor
simulator::simulator( const char *fileName, int maxAverage)
{
    this->fileName = fileName;
    this->maxAverage = maxAverage;
}

void simulator::simulate()
{
    // open file
    ifstream in( fileName);

    int n;
    in >> n;

    int patients[n][4];
    int i = 0;

    // read from file
    while( in >> patients[i][0] >> patients[i][1] >> patients[i][2] >> patients[i][3])
        ++i;

    // try until finding the min # of doctors
    int doctors = 0;
    double average = 0;
    while( true)
    {
        ++doctors;
        int arrDoctors[200];
        for( int i = 0; i < 200; ++i)
            arrDoctors[i] = 0;
        pq pq;
        int pt_id, pt_arrival, pt_treatment;
        int total_wait = 0;
        int time = patients[0][2];
        pq.push( patients[0][0], patients[0][1], patients[0][2], patients[0][3]);
        for( int i = 1; i < n; ++i)
        {
            if ( time != patients[i][2])  // if time elapsed
            {
                time = patients[i][2];    // update time

                // check the availability of doctors for the current time
                for( int j = 0; j < doctors; ++j)
                    if( arrDoctors[j] < time && !pq.isEmpty())
                    {
                        pq.pop( pt_id, pt_arrival, pt_treatment);
                        arrDoctors[j] = max( pt_arrival, arrDoctors[j]);
                        total_wait += arrDoctors[j] - pt_arrival;
                        arrDoctors[j] += pt_treatment;      // the time when doctor will be available
                    }

                pq.push( patients[i][0], patients[i][1], patients[i][2], patients[i][3]);

                if( (double)(total_wait) / n > maxAverage)  // the condition is already breached
                    break;                                  // the # of doctors needs to be increased
            }
            else    // time did not elapse
                pq.push( patients[i][0], patients[i][1], patients[i][2], patients[i][3]);
        } // end of for

        while( !pq.isEmpty())
        {
            ++time;
            // check for availability of doctors in the current time
            for( int j = 0; j < doctors; ++j)
                if( arrDoctors[j] < time && !pq.isEmpty())
                {
                    pq.pop( pt_id, pt_arrival, pt_treatment);
                    arrDoctors[j] = max( pt_arrival, arrDoctors[j]);
                    total_wait += arrDoctors[j] - pt_arrival;
                    arrDoctors[j] += pt_treatment;      // the time when doctor will be available
                }
        }

        //check whether the # of doctors satisfies the condition
        if( (double)(total_wait) / n <= maxAverage)
        {
            average = (double)(total_wait) / n;
            break;
        }
    } // end of while

    // simulate the process
    cout << endl;
    cout << "Minimum number of doctors required: " << doctors << endl << endl;
    cout << "Simulation with " << doctors << " doctors:" << endl << endl;

    int arrDoctors[200];
    for( int i = 0; i < 200; ++i)
        arrDoctors[i] = 0;
    pq pq;
    int pt_id, pt_arrival, pt_treatment;
    int time = patients[0][2];
    pq.push( patients[0][0], patients[0][1], patients[0][2], patients[0][3]);
    for( int i = 1; i < n; ++i)
    {
        if ( time != patients[i][2])  // if time elapsed
        {
            time = patients[i][2];    // update time

            // check the availability of doctors for the current time
            for( int j = 0; j < doctors; ++j)
                if( arrDoctors[j] < time && !pq.isEmpty())
                {
                    pq.pop( pt_id, pt_arrival, pt_treatment);
                    arrDoctors[j] = max( pt_arrival, arrDoctors[j]);
                    cout << "Doctor " << j << " takes patient " << pt_id << " at minute " << arrDoctors[j] << " (wait: " << arrDoctors[j] - pt_arrival << " mins)" << endl;
                    arrDoctors[j] += pt_treatment;      // the time when doctor will be available
                }

            pq.push( patients[i][0], patients[i][1], patients[i][2], patients[i][3]);
        }
        else    // time did not elapse
            pq.push( patients[i][0], patients[i][1], patients[i][2], patients[i][3]);
    } // end of for

    while( !pq.isEmpty())
    {
        ++time;
        // check for availability of doctors in the current time
        for( int j = 0; j < doctors; ++j)
            if( arrDoctors[j] < time && !pq.isEmpty())
            {
                pq.pop( pt_id, pt_arrival, pt_treatment);
                arrDoctors[j] = max( pt_arrival, arrDoctors[j]);
                cout << "Doctor " << j << " takes patient " << pt_id << " at minute " << arrDoctors[j] << " (wait: " << arrDoctors[j] - pt_arrival << " mins)" << endl;
                arrDoctors[j] += pt_treatment;      // the time when doctor will be available
            }
    }

    cout << endl << "Average waiting time: " << average << " minutes" << endl << endl;
}
