#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Process{
    public:
    int p_id;
    int priority;
    int burstTime;
};

class ComparePriority{
    public:
   bool operator()(const Process& p1, const Process& p2)
    {
        return p1.priority > p2.priority;
    }
};

bool ABC(priority_queue<Process, vector<Process>, ComparePriority> q1, int current_priority){
    if(q1.empty())
    {
        return false;
    }
    return q1.top().priority < current_priority;
}

int main(){
   
    priority_queue<Process, vector<Process>, ComparePriority> Priorityque;
  
    queue <Process> RRque;
    
    Priorityque.push({1, 1, 6});
    Priorityque.push({2, 0, 4});
    Priorityque.push({3, 2, 2});
    Priorityque.push({4, 3, 5});
    
    while(!Priorityque.empty()){
        Process Current_process = Priorityque.top();
        Priorityque.pop();
        
        for(int i = 0; i<Current_process.burstTime; i+=2){
            
            cout << "Executing process" << Current_process.p_id << endl;
            
           if(ABC(Priorityque, Current_process.priority))
            {
                Current_process.burstTime -= (i + 2);
                RRque.push(Current_process);
                break;
            } 
             else
            {
                Current_process.burstTime -= 2; 

            }
        }
        if(Current_process.burstTime <= 0)
        {
            cout << "Process " << Current_process.p_id << " has completed execution." << endl;
        }
        else
        {
            Priorityque.push(Current_process);
        }
    }
    
     while(!RRque.empty()) {
        Process current_process = RRque.front(); 
        RRque.pop();
        for(int i = 0; i < 4; i++) {
            cout << "Executing Process " << current_process.p_id <<  endl;
            current_process.burstTime--;
            
            if(current_process.burstTime <= 0) { 
                cout << "Process " << current_process.p_id << " has completed execution." << endl; 
                break; 
            }
            
            }
            if(current_process.burstTime > 0) { 
                RRque.push(current_process); 
        }
    }
    return 0;
}















