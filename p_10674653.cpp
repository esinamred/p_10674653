#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

template <class var>

void output(var textline){
    cout << textline;
}



struct course {
    int level;
    string subjects[10];
};

struct record{
    int sem;
    int credit_hr;
    string course_name;
    int mark;
    string grade;
};


class person
{
    public:
        person()
        {
            status = "null";
        }
        void setName(string val){
            name = val;
        }

        void setStatus(string val){
            status = val;
        }

        void setAge(int val){
            age = val;
        }

        void setID(int val){
            object_id = val;
        }

        void setIndex(int val){
            index = val;
        }

        void setResidence(string val){
            residence = val;
        }

        void listItems(vector <string> arrayVar){
            int len = arrayVar.size();
            for (int i=0;i<len;i++){
                output(arrayVar[i]);
                if ((i+1)%3 == 0){
                    output("\n");
                }else{
                    output("\t\t");
                }
            }
        }


        string getName(){
            return name;
        }

        string getStatus(){
            return status;
        }

        int getAge(){
            return age;
        }

        string getResidence(){
            return residence;
        }

        string getType(){
            return "person";
        }

        int getID(){
            return object_id;
        }

        int getIndex(){
            return index;
        }

        void getInfo(){
            cout << "\nname       : " << getName() << "\nage        : " << getAge() << "\nperson ID    : " << getID() <<endl;
        }

    private:
        string name;
        int age;
        int index;
        int object_id;
        string status;
        string residence;
};


struct student{
    person details;
    float schoolfees;
    int level;
    string course;
    string department;
    vector<string> subjects;
    vector<record> academic_records;
};

struct staff{
    person details;
    string job;
    string department;
    vector<string> subjects;
};


void addStudent(),editStudent(),manageStudent(),GpaCalc(student obj);
void addStaff(),editStaff(),manageStaff(),GpaCalc(student obj);
string lower(string line),gradeCalc(double score);

student Stu_set[50000];
staff Sta_set[50000];


int stu_base_id=10000000;
int sta_base_id=11000000;
int stu_count = 0;
int sta_count = 0;
string str;int num;



int main()
{
	output("APP DEVELOPED BY ESINAMN JANET AWUKU, ID NUMBER 10674653 AND EMAILJEAWUKU@ST.UG.EDU.GH");
    output("\n\nWELCOME TO THE UNIVERSITY OF GHANA SCHOOL MANAGEMENT SYSTEM\n");
    string option;

    while (true){
       output("\n1. student \n2. staff \n0. exit\n");
       output("\nselect an option : ");
       cin >> str;
       if (str == "1"){
            output("\nstudent directory");
            while (true){
                output("\n\n1. add \n2. edit \n3. manage \n0. exit");
                output("\n\nselect an option : ");
                cin >> option;
                if (option == "1"){
                    addStudent();
                }
                else if (option == "2"){
                    editStudent();
                }
                else if (option == "3"){
                    manageStudent();
                }
                else if (option == "0"){
                    break;
                }
                cin.clear();
            }
        }
        else if (str == "2"){
            output("\nstaff route");
            while (true){
                output("\n\n1. add \n2. edit \n3. manage \n0. exit");
                output("\n\nselect person : ");
                cin >> option;
                if (option == "1"){
                    addStaff();
                }
                else if (option == "2"){
                    editStaff();
                }
                else if (option == "3"){
                    manageStaff();
                }
                else if (option == "0"){
                    break;
                }
                cin.clear();
            }
        }
        else if (str == "0"){
            break;
        }
    }
    return 0;
}


void addStudent(){
    cin.clear();
    output("\n**************adding new student*****************");
    student temp;
    output("\nAssigned Student ID : ");output(stu_base_id+stu_count);
    temp.details.setID(stu_base_id+stu_count);temp.details.setIndex(stu_count);stu_count++;
    string str;int num;
    output("\nEnter Students Name : ");
    cin.ignore();getline(cin, str);cin.clear();
    temp.details.setName(str);
    output("\nEnter Students Age : ");
    cin >> num;
    while (cin.fail()){
        output("\n( invalid ) Try Again : ");
        cin.clear();cin.ignore();cin >> num;
    }
    temp.details.setAge(num);
    output("\nEnter Department Name : ");
    cin >> str;
    temp.department = str;
    output("\nEnter Students Course : ");
    cin >> str;
    temp.course = str;
    output("\nEnter Students Level  : ");
    cin >> num;
    while (cin.fail()){
        output("\n( invalid ) Try Again : ");
        cin.clear();cin.ignore();cin >> num;
    }
    while (num != 100 && num != 200 && num != 300 && num != 400){
        output("( invalid ) Enter Level  : ");
        cin >> num;
        while (cin.fail()){
            output("\n( invalid ) Try Again : ");
            cin.clear();cin.ignore();cin >> num;
        }
    }
    temp.level = num;
    output("\nEnter Students School Fees : ");
    cin >> num;
    while (cin.fail()){
        output("\n( invalid ) Try Again  : ");
        cin.clear();cin.ignore();cin >> num;
    }
    temp.schoolfees = num;

    Stu_set[temp.details.getIndex()] = temp;

    output("\nDo you want to add another student? (y/n) : ");
    cin >> str;
    if (str == "y"){
        addStudent();
    }
    else{
    }

};

void editStudent(){
int pass = 1;
output("\n( edit ) Enter students ID or 0 to leave : ");
int stu_id;
cin >> stu_id;
while (cin.fail()){
    output("\n( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> stu_id;
}
if (stu_id != 0){

    stu_id -= stu_base_id;
    while (stu_id < 0 || stu_id >= stu_count){
        output("\n( invalid ) Enter Students ID or 0 to leave : ");
        cin >> stu_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            output("\n( invalid ) Enter valid student ID : ");
            cin >> stu_id;
        }
        if(stu_id != 0){
            stu_id -= stu_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        output("\nStudent Found\n");
        student obj = Stu_set[stu_id];
        while (true){
            output("\n\n1. name \n2. age \n3. level \n4. course \n5. department \n6. student subjects \n7. residence \n0. exit\n");
            output("\nWhat do you want to edit : ");
            string edit;
            cin >> edit;
            if (edit == "1"){
                output("\nStudents name : ");output(obj.details.getName());
                output("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
            }
            else if (edit == "2"){
                output("\nStudents age : ");output(obj.details.getAge());
                output("\n\nChange to : ");
                cin >> num;
                while (cin.fail()){
                    output("\n( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> num;
                }
                obj.details.setAge(num);
            }
            else if (edit == "3"){
                output("\nStudents level : ");output(obj.level);
                output("\n\nChange to : ");
                cin >> num;
                while (cin.fail()){
                    output("\n( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> num;
                }
                while (num != 100 && num != 200 && num != 300 && num != 400){
                    output("\n\nChange to 100,200,300 or 400 : ");
                    cin >> num;
                    while (cin.fail()){
                        output("\n( invalid ) Try Again : ");
                        cin.clear();cin.ignore();cin >> num;
                    }
                }
                obj.level = num;
            }
            else if (edit == "4"){
                output("\nStudents course : ");output(obj.course);
                cin.ignore();getline(cin, str);cin.clear();
                obj.course = str;
            }
            else if (edit == "5"){
                output("\nStudents Department : ");output(obj.department);
                output("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                obj.department = str;
            }
            else if (edit == "6"){
                output("\n\n\nStudents subject : \n");
                while (true){
                    output("1. add subject \n2. remove subject \n0. exit\n");
                    output("select an option : ");
                    cin >> str;
                    if (str == "1"){
                        cin.ignore();
                        while (true){
                            output("\nenter subject to add or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                               obj.subjects.push_back(str);
                               record _new;
                               _new.course_name = str;
                               _new.mark = -1;
                               obj.academic_records.push_back(_new);
                            }
                        }

                    }
                    else if (str == "2"){
                        cin.ignore();
                        while (true){
                            output("\nenter subject to remove or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                                int len = obj.subjects.size();
                                for (int i=0;i<len;i++){
                                    if (lower(obj.subjects[i]) == lower(str)){
                                        obj.subjects.erase(obj.subjects.begin()+i);
                                        obj.academic_records.erase(obj.academic_records.begin()+i);
                                        output("\nSubject successfully removed ...");
                                        break;
                                    }
                                    if (i == len-1){
                                        output("\ncant find subject index ...\n");
                                    }
                                }
                            }
                        }
                    }else if (str == "0"){
                        break;
                    }
                }

            }
            else if (edit == "7"){
                output("\nStudents Residence : ");output(obj.details.getResidence());
                output("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                cin.clear();obj.details.setResidence(str);
            }
            else if (edit == "0"){
                Stu_set[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void manageStudent(){
int pass = 1;
output("\n( manage )Enter students ID or 0 to leave : ");
int stu_id;
cin >> stu_id;
while (cin.fail()){
    output("\n( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> stu_id;
}
if (stu_id != 0){

    stu_id -= stu_base_id;
    while (stu_id < 0 || stu_id >= stu_count){
        output("\n( invalid ) Enter Students ID or 0 to leave : ");
        cin >> stu_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            output("\n( invalid ) Enter valid student ID : ");
            cin >> stu_id;
        }
        if(stu_id != 0){
            stu_id -= stu_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        output("\nStudent Found\n");
        student obj = Stu_set[stu_id];
        while (true){
            output("\n\n1. enter students score \n2. show academic records \n3. remove student \n0. exit\n");
            output("\nWhat do you want to do : ");
            string manage;
            cin >> manage;
            if (manage == "1"){
                int len = obj.subjects.size();
                output("Enter the sem? (1,2) : ");
                cin >> num;
                while (num != 1 && num != 2){
                    output("Enter the sem? (1,2) : ");
                    cin >> num;
                }
                for (int i=0;i<len;i++){
                    if (obj.academic_records[i].mark == -1){
                        output("\n\nSubject :\t");output(obj.academic_records[i].course_name);
                        output("\nDo you want to record marks for this subject : ");
                        cin >> str;str = lower(str);
                        while (str != "y" && str != "n"){
                            output("\nplease choose 'y' or 'n'");
                            cin >> str;
                            str = lower(str);
                        }
                        if (str == "y"){
                            int credit_h;
                            output("\nCredit Hour(s)\t:\t");
                            cin >> credit_h;
                            while (0 > credit_h || credit_h > 3){
                                output("(invalid) Credit Hour(s)\t:\t");
                                cin >> credit_h;
                            }
                            int score;
                            output("Enter Mark\t:\t");
                            cin >> score;
                            while (0 > score || score >100){
                                output("(invalid) Enter Mark\t:\t");
                                cin >> score;
                            }
                            obj.academic_records[i].mark = score;
                            obj.academic_records[i].credit_hr = score;
                            obj.academic_records[i].sem = num;
                            obj.academic_records[i].grade = gradeCalc(score);
                        }
                    }
                }
                Stu_set[obj.details.getIndex()] = obj;
            }
            else if (manage == "2"){
                int len = obj.subjects.size();
                output("\n\n############################################################################################");
                output("\n********************************************************************************************");
                output("\nName : ");output(obj.details.getName());output("\tDepartment : ");output(obj.department);
                output("\tCourse : ");output(obj.course);output("\tLevel : ");output(obj.level);output("\tGPA :\t");GpaCalc(obj);
                output("\n********************************************************************************************");
                output("\n============================================================================================");
                for (int i=0;i<len;i++){
                    if (obj.academic_records[i].mark != -1){
                        output("\n\nSubject :\t");output(obj.academic_records[i].course_name);
                        output("\t\tMark :\t");output(obj.academic_records[i].mark);
                        output("\t\tGrade :\t");output(obj.academic_records[i].grade);
                    }
                    else{
                        output("\n\nSubject :\t");output(obj.academic_records[i].course_name);
                        output("\t\tMark :\t");output("**N/A**");
                        output("\t\tGrade :\t");output("**N/A**");
                    }
                }
                output("\n\n============================================================================================");
                output("\n############################################################################################");
            }
            else if (manage == "3"){
                output("\nAre you sure you want to remove student? (y/n) : ");
                cin >> str;str = lower(str);
                while (str != "y" && str != "n"){
                    output("\nplease choose 'y' or 'n'");
                    cin >> str;
                    str = lower(str);
                }
                if (str == "y"){
                    obj.details.setStatus("removed");
                    Stu_set[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "0"){
                //commit changes and push
                Stu_set[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};

void addStaff(){
    cin.clear();
    output("\n**************adding new staff*****************");
    staff temp;
    output("\n\nAssigned Staff ID : ");output(sta_base_id+sta_count);
    temp.details.setID(sta_base_id+sta_count);temp.details.setIndex(sta_count);sta_count++;
    string str;int num;
    output("\nEnter Staff Name : ");
    cin.ignore();getline(cin, str);cin.clear();
    temp.details.setName(str);
    output("\nEnter Staff Age : ");
    cin >> num;
    while (cin.fail()){
        output("\n( invalid ) Try Again : ");
        cin.clear();cin.ignore();cin >> num;
    }
    temp.details.setAge(num);
    output("\nEnter Department Name : ");
    cin >> str;
    temp.department = str;

    output("\nEnter Staffs Job : ");
    cin >> str;
    temp.job = str;

    Sta_set[temp.details.getIndex()] = temp;

    output("\nDo you want to add another staff? (y/n) : ");
    cin >> str;
    if (str == "y"){
        addStaff();
    }
    else{
    }

};

void editStaff(){
int pass = 1;
output("\n( edit ) Enter Staffs ID or 0 to leave : ");
int sta_id;
cin >> sta_id;
while (cin.fail()){
    output("\n( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> sta_id;
}
if (sta_id != 0){
    sta_id -= sta_base_id;
    while (sta_id < 0 || sta_id >= stu_count){
        output("\n( invalid ) Enter Staffs ID or 0 to leave : ");
        cin >> sta_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            output("\n( invalid ) Enter valid Staff ID : ");
            cin >> sta_id;
        }
        if(sta_id != 0){
            sta_id -= sta_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        output("\nStaff Found\n");
        staff obj = Sta_set[sta_id];
        while (true){
            output("\n\n1. name \n2. age \n3. department \n4. staff subjects \n5. residence \n0. exit\n");
            output("\nWhat do you want to edit : ");
            string edit;
            cin >> edit;
            if (edit == "1"){
                output("\nStaffs name : ");output(obj.details.getName());
                output("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
            }
            else if (edit == "2"){
                output("\n\nChange to : ");
                cin >> num;
                while (cin.fail()){
                    output("\n( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> num;
                }
                obj.details.setAge(num);
            }
            else if (edit == "3"){
                output("\nStaffs Department : ");output(obj.department);
                output("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                obj.department = str;
            }
            else if (edit == "4"){
                output("\n\n\nStaffs subject : \n");
                while (true){
                    output("1. add subject \n2. remove subject \n0. exit\n");
                    output("select an option : ");
                    cin >> str;
                    if (str == "1"){
                        cin.ignore();
                        while (true){
                            output("\nenter subject to add or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                               obj.subjects.push_back(str);
                            }
                        }

                    }
                    else if (str == "2"){
                        cin.ignore();
                        while (true){
                            output("\nenter subject to remove or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                                int len = obj.subjects.size();
                                for (int i=0;i<len;i++){
                                    if (lower(obj.subjects[i]) == lower(str)){
                                        obj.subjects.erase(obj.subjects.begin()+i);
                                        output("\nSubject successfully removed ...");
                                        break;
                                    }
                                    if (i == len-1){
                                        output("\ncant find subject index ...\n");
                                    }
                                }
                            }
                        }
                    }else if (str == "0"){
                        break;
                    }
                }
            }
            else if (edit == "5"){
                output("\nStaffs Residence : ");output(obj.details.getResidence());
                output("\n\nChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                cin.clear();obj.details.setResidence(str);
            }
            else if (edit == "0"){
                Sta_set[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void manageStaff(){
int pass = 1;
output("\n( manage )Enter Staffs ID or 0 to leave : ");
int sta_id;
cin >> sta_id;
while (cin.fail()){
    output("\n( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> sta_id;
}
if (sta_id != 0){
    sta_id -= sta_base_id;
    while (sta_id < 0 || sta_id >= sta_count){
        output("\n( invalid ) Enter Staff ID or 0 to leave : ");
        cin >> sta_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            output("\n( invalid ) Enter valid staff ID : ");
            cin >> sta_id;
        }
        if(sta_id != 0){
            sta_id -= sta_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        output("\nStaff Found\n");
        staff obj = Sta_set[sta_id];
        while (true){
            output("\n\n1. remove staff \n0. exit\n");
            output("\nWhat do you want to do : ");
            string manage;
            cin >> manage;
            if (manage == "1"){
                output("\nAre you sure you want to remove staff? (y/n) : ");
                cin >> str;str = lower(str);
                while (str != "y" && str != "n"){
                    output("\nplease choose 'y' or 'n'");
                    cin >> str;
                    str = lower(str);
                }
                if (str == "y"){
                    obj.details.setStatus("removed");
                    Sta_set[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "0"){
                Sta_set[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};


string lower(string line){
    string LOWER = "abcdefghijklmnopqrstuvwxyz";
    string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret_lower = "";
    int len = line.length();
    for (int i=0;i<len;i++){//boy
        for (int j=0;j<26;j++){
            if (line[i] == UPPER[j]){
                ret_lower += LOWER[j];
                break;
            }
            else if (j == 25){
                ret_lower += line[i];
            }
        }

    }
    return ret_lower;
}


string gradeCalc(double score){
    if (79 < score && score <= 100){
        return "A";
    }
    else if(74 < score && score <= 79){
        return "B+";
    }
    else if(69 < score && score <= 74){
        return "B";
    }
    else if(64 < score && score <= 69){
        return "C+";
    }
    else if(59 < score && score <= 64){
        return "C";
    }
    else if(54 < score && score <= 59){
        return "D+";
    }
    else if(49 < score && score <= 54){
        return "D";
    }
    else if(44 < score && score <= 49){
        return "E";
    }
    else if(-1 < score && score <= 44){
        return "F";
    }
    else{
        return "invalid mark";
    }
}


float getGpaScore(string grade){
    if (grade == "A"){
        return 4.0;
    }
    else if (grade == "B+"){
        return 3.5;
    }
    else if (grade == "B"){
        return 3.0;
    }
    else if (grade == "C+"){
        return 2.5;
    }
    else if (grade == "C"){
        return 2.0;
    }
    else if (grade == "D+"){
        return 1.5;
    }
    else if (grade == "D"){
        return 1.0;
    }
    else if (grade == "E"){
        return 0.5;
    }
    else if (grade == "F"){
        return 0.0;
    }
    return -1;
}

void GpaCalc(student obj){
    float gpa = 0.0;int tch=0;bool empty_score = false;
    int len = obj.academic_records.size();
    vector<record> temp_record = obj.academic_records;
    for (int i=0;i<len;i++){
        if (temp_record[i].mark == -1){
            empty_score = true;
            cout << "**N/A**";
            break;
        }
        else{
            tch += temp_record[i].credit_hr;
            gpa += getGpaScore(temp_record[i].grade)*temp_record[i].credit_hr;
        }
    }
    if (empty_score == false){
        if (len != 0){
            cout << gpa/tch;
        }
        else{
            cout << "**N/A**";
        }
    }
}
