
#include <iostream>
#include <fstream>
#include<string>
#include <iomanip>
using namespace std;

class Process{
    public:
    int Pid;
    int arrival_t;
    int burst_t;
    int wating_t; 
    int turnaround_t;
    int terminate_t;
     // Overloading of Assignment Operator
    void operator=(const Process &t ) { 
       Pid=t.Pid;
       arrival_t=t.arrival_t;
       burst_t=t.burst_t;
       
    }  
};

int No_procs=0;//#process to be schedule
Process *p=new Process[20];// ready queue with 20 processes at maximum

void Sort_by_arrivalT(Process *t){// Function to sort the processes by their arrival time
int i=0,j=0;Process temp;
for(i=0;i<No_procs;i++)
{
 for(j=i;j>=1;j--)
  { if(p[j].arrival_t<p[j-1].arrival_t)
      {
          temp=p[j-1];
          p[j-1]=p[j];
          p[j]=temp;
       }
 }
}
}
int cputime=0;
void FCFS_Simulator(Process *t){
    
    for(int i=0; i<No_procs;i++){
		//loop to check if there is a process in the CPU
		for( cputime ; cputime<p[i].arrival_t;++cputime){
			cout<<"< system time "<<cputime<<"> is idle"<<endl;}
		
		p[i].wating_t=cputime-p[i].arrival_t;//calculating  waiting time for each process

		p[i].terminate_t=cputime+p[i].burst_t;//find the terminate time for the current process
                
		p[i].turnaround_t=p[i].terminate_t-p[i].arrival_t;//calculating  turnaround time for each process

		for(cputime; cputime<p[i].terminate_t;++cputime){
		cout<<"< system time "<<cputime<<" > process "<<p[i].Pid<<" is running "<<endl;}
		
		cout<<"< system time "<<cputime<<" > process "<<p[i].Pid<<" is finished ....... "<<endl;	
    }
	cout<<"< system time "<<cputime<<" > All processes are finish ................... "<<endl;
}

void Calculate(Process *t){
    
float totalWatingTime=0 , TotalTurnaroundTime=0 ,totalBarstTime=0;
	for(int i=0;i<No_procs;i++)
	{
		//actual cpu time
		totalBarstTime+=p[i].burst_t;
		totalWatingTime+=p[i].wating_t;
		TotalTurnaroundTime+=p[i].turnaround_t;
	}
        cout<<"==========================================="<<endl;
cout <<"Avarage cpu usage        : "<<setprecision(2)<<fixed<<(totalBarstTime/cputime)*100<<endl;
cout <<"Avarage wating time      : "<<setprecision(2)<<fixed<<totalWatingTime/No_procs<<endl;
cout <<"Avarage turnaround time  : "<<setprecision(2)<<fixed<<TotalTurnaroundTime/No_procs<<endl;
        cout<<"==========================================="<<endl;
        
}

void print_gantt_chart(Process *p)
{
	
    int i, j=0,x=0;
    // print top bar

	 for(i=0; i<No_procs; i++) {
		if(x<p[i].arrival_t){
		for(x;x<p[i].arrival_t;++x)cout<<"  "; 
		cout<<" ";}
        for(j=x; j<p[i].terminate_t-1; ++j) cout<<"-";
        cout<<"--";
        for(x; x<=p[i].terminate_t-1; ++x) cout<<"-";
        cout<<" ";
    }x=0;


	cout<<endl;
    // printing process id in the middle
    for(i=0; i<No_procs; i++) {
		if(x<p[i].arrival_t){
		for(x;x<p[i].arrival_t;++x)cout<<"  "; 
		cout<<"|";}
        for(j=x; j<p[i].terminate_t-1; ++j) cout<<" ";
        cout<<"P"<<p[i].Pid;
        for(x; x<=p[i].terminate_t-1; ++x) cout<<" ";
        cout<<"|";
    }x=0;
    cout<<"\n";
    
    // printing bottom bar
	 for(i=0; i<No_procs; i++) {
		if(x<p[i].arrival_t){
		for(x;x<p[i].arrival_t;++x)cout<<"-"; 
		cout<<" ";}
        for(j=x; j<p[i].terminate_t-1; ++j) cout<<"-";
        cout<<"--";
        for(x; x<=p[i].terminate_t-1; ++x) cout<<"-";
        cout<<" ";
    }x=0;
  
	cout<<"\n";

    // printing the time line
    cout<<"0";
	 for(i=0; i<No_procs; i++) {
		if(x<p[i].arrival_t){
		for(x;x<p[i].arrival_t;++x)cout<<"  "; 
		cout<<p[i].arrival_t;}
        for(j=x; j<p[i].terminate_t-1; ++j) cout<<" ";
        cout<<" ";
        for(x; x<=p[i].terminate_t-1; ++x) cout<<" ";
        cout<<p[i].terminate_t;
    }
  
    cout<<"\n";

} 


int main() {
    ifstream myfile("input.txt");// Open input file
    string line;  
  
    if(myfile.is_open()){
    // Read and throw away the first 2 lines simply by doing
    // nothing with it and reading again
    getline( myfile, line );//1st line
    cout<<line<<endl;
    getline( myfile, line );//2nd line
    cout<<line<<endl;
     // begin my useful code
      while(!myfile.eof()&& No_procs<=20){
          
          myfile>>p[No_procs].Pid>>p[No_procs].arrival_t>>p[No_procs].burst_t;
          cout<<" "<<p[No_procs].Pid<<"        "<<p[No_procs].arrival_t<<"          "<<p[No_procs].burst_t<<endl;
          No_procs++;
          if(No_procs==20) break; 
          }
      myfile.close();
    }
  
   Sort_by_arrivalT(p);// call function to sort process to be scheduled 
    

//------------------------------------------- 
   
cout<<"\n";
cout<<"********************************************************************"<<endl;
cout<<"Scheduling Algorthim: FCFS total "<<No_procs<<" tasks are read from \"input.txt\""<<endl;
cout<<"********************************************************************"<<endl<<endl;

FCFS_Simulator(p);//Print progress of task every millisecond
cout<<"\n";
cout<<"             "<<"***************************************"<<endl;
cout<<"                           "<<"Gantt Chart"<<endl;
cout<<"             "<<"***************************************"<<endl<<endl;
print_gantt_chart(p);// print Gantt 
Calculate(p); //Calculating total Burst Time,waiting time ,Turnaround Time and response time.
   

	


    return 0;
}
