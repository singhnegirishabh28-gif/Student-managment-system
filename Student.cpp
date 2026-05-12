#include<iostream>
#include<cstring>
using namespace std;

class Student
{
public:
    int roll;
    char name[50];
    float marks;
};

int main()
{
    Student s[100];
    int choice, count = 0;

    while(true)
    {
        cout<<"\n===== Student Management System =====\n";
        cout<<"1. Add Student\n";
        cout<<"2. Display Students\n";
        cout<<"3. Search Student\n";
        cout<<"4. Update Student\n";
        cout<<"5. Delete Student\n";
        cout<<"6. Sort by Marks\n";
        cout<<"7. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice == 1)
        {
            if(count >= 100)
            {
                cout<<"Limit Reached!\n";
                continue;
            }

            cout<<"Enter Roll Number: ";
            cin>>s[count].roll;

            cout<<"Enter Name: ";
            cin.ignore();
            cin.getline(s[count].name, 50);

            cout<<"Enter Marks: ";
            cin>>s[count].marks;

            count++;
            cout<<"Student Added Successfully!\n";
        }

        else if(choice == 2)
        {
            if(count == 0)
            {
                cout<<"No Records Found!\n";
            }
            else
            {
                cout<<"\n--- Student Records ---\n";
                for(int i = 0; i < count; i++)
                {
                    cout<<"\nStudent "<<i+1<<endl;
                    cout<<"Roll: "<<s[i].roll<<endl;
                    cout<<"Name: "<<s[i].name<<endl;
                    cout<<"Marks: "<<s[i].marks<<endl;
                }
            }
        }

        else if(choice == 3)
        {
            int r, found = 0;
            cout<<"Enter Roll Number to Search: ";
            cin>>r;

            for(int i = 0; i < count; i++)
            {
                if(s[i].roll == r)
                {
                    cout<<"Record Found:\n";
                    cout<<"Name: "<<s[i].name<<endl;
                    cout<<"Marks: "<<s[i].marks<<endl;
                    found = 1;
                    break;
                }
            }

            if(!found)
                cout<<"Student Not Found!\n";
        }

        else if(choice == 4)
        {
            int r, found = 0;
            cout<<"Enter Roll Number to Update: ";
            cin>>r;

            for(int i = 0; i < count; i++)
            {
                if(s[i].roll == r)
                {
                    cout<<"Enter New Name: ";
                    cin.ignore();
                    cin.getline(s[i].name, 50);

                    cout<<"Enter New Marks: ";
                    cin>>s[i].marks;

                    cout<<"Record Updated!\n";
                    found = 1;
                    break;
                }
            }

            if(!found)
                cout<<"Student Not Found!\n";
        }

        else if(choice == 5)
        {
            int r, found = 0;
            cout<<"Enter Roll Number to Delete: ";
            cin>>r;

            for(int i = 0; i < count; i++)
            {
                if(s[i].roll == r)
                {
                    for(int j = i; j < count - 1; j++)
                    {
                        s[j] = s[j+1];
                    }
                    count--;
                    cout<<"Record Deleted!\n";
                    found = 1;
                    break;
                }
            }

            if(!found)
                cout<<"Student Not Found!\n";
        }

        else if(choice == 6)
        {
            for(int i = 0; i < count-1; i++)
            {
                for(int j = i+1; j < count; j++)
                {
                    if(s[i].marks < s[j].marks)
                    {
                        Student temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }
            }
            cout<<"Sorted by Marks (Descending)\n";
        }

        else if(choice == 7)
        {
            cout<<"Exiting Program...\n";
            break;
        }

        else
        {
            cout<<"Invalid Choice!\n";
        }
    }
    return 0;
} 

