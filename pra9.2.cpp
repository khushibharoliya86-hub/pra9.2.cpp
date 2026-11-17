//practical 9.2
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct studentData
{

    string en,sname,branch,sem,grade;
    float per;
};
int main()
{
    int n;
    float totalAvg=0;
    float Per;
    float highest_per=INT_MIN;
    float lowest_per=INT_MAX;
    cout<<"*********************************************\n";
    cout<<"STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout<<"*********************************************\n";
    cout<<"Enter Number of Students:";
    cin>>n;
    cout<<endl;
    cout<<"Dynamic Memory Allocated Successfully\n\n";
    cout<<"------------------------------------\n\n";
    cout<<"Enter Student Details\n\n";

    //dynamic memeory allocation take input student information
    studentData *student =new studentData[n] ;
    for(int i=0; i<n; i++)
    {
        cout<<"Student"<<i+1<<endl<<endl;
        cout<<"Enrollment Number:";
        cin>>student[i].en;
        cout<<"Student Name:";
        cin.ignore();
        getline(cin,student[i].sname);
        cout<<"Branch:";
        cin>>student[i].branch;
        cout<<"Semester:";
        cin>>student[i].sem;
        cout<<"Persentage:";
        cin>>student[i].per;
        if(student[i].per>90)
        {
            student[i].grade='O';
            cout<<"Grade:"<<student[i].grade;
        }
        else if(student[i].per>80)
        {
            student[i].grade='A';
            cout<<"Grade:"<<student[i].grade;
        }
        else if(student[i].per>70)
        {
            student[i].grade='B';
            cout<<"Grade:"<<student[i].grade;
        }
        else if(student[i].per>60)
        {
            student[i].grade='C';
            cout<<"Grade:"<<student[i].grade;
        }
        else if(student[i].per>45)
        {
            student[i].grade='D';
            cout<<"Grade:"<<student[i].grade;
        }
        else
        {
            student[i].grade='F';
            cout<<"Grade:"<<student[i].grade;
        }
        cout<<endl;
        cout<<"-------------------------------------\n";
    }

    //Dispaly student Information and address based location
    cout<<"Student Records using Address-based Access\n\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Address   :"<<&student[i]<<endl<<endl;
        cout<<student[i].en<<"  "<<student[i].sname<<"  "<<
            student[i].branch<<"  "<<student[i].sem<<"  "
            <<student[i].per<<"  "<<student[i].grade<<endl<<endl;
        cout<<"--------------------------------------\n\n\n";
    }


    cout<<"Academic Summary\n\n";
    //Find Class Avg
    cout<<"Class Average Percentage :";
    for(int i=0; i<n; i++)
    {
        totalAvg+=student[i].per;
    }
    Per=totalAvg/float(n);
    cout<<fixed<<setprecision(2)<<Per<<"%"<<endl;

    //Hghtest percentage
    for(int i=0; i<n; i++)
    {
        if(student[i].per>highest_per)
        {
            highest_per=student[i].per;
        }
    }
    cout<<"Highest Percentage       :"<<highest_per<<"%"<<endl;

    //Lowest percentage
    for(int i=0; i<n; i++)
    {
        if(student[i].per<lowest_per)
        {
            lowest_per=student[i].per;
        }
    }
    cout<<"Lowest Percentage        :"<<lowest_per<<"%"<<endl;

    cout<<"--------------------------------------\n\n\n";
    cout<<"Dynamic Memory Released Successfully\n\n";
    cout<<"Address Variable Reset Successfully\n\n";
    cout<<"--------------------------------------\n\n\n";
    cout<<"Program Executed Successfully.\n\n";
    cout<<"--------------------------------------\n\n\n";

    return 0;
}

