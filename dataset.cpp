//#include"test 3.hpp"
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//
//class myData {
//private:
//    string ip;
//    string date;
//    string time;
//public:
//    myData() {}
//    void setip(string i){
//        ip = i;
//    }
//    void setdate(string d) {
//        date = d;
//    }
//    void settime(string t) {
//        time = t;
//    }
//    string getip() {
//        return ip;
//    }
//    string getdate() {
//        return date;
//    }
//    string gettime() {
//        return time;
//    }
//};
//
//
//int main() {
//    ifstream infile;
//    try
//    {
//        infile.open("log20170630.csv");//trying to open the file
//        if (infile.fail()) {
//            throw "file does not exist";//error message if file doesnt exist
//        }
//    }
//    catch (const char* e)
//    {
//        cerr << e << endl;//displaying the error message 
//    }
//    string ip;
//    string date;
//    string time;
//
//    while (getline(infile, ip)) {//looping while there are still values to obtain
//        getline(infile, ip, ',');//setting the ip,date,time variables to those from the file
//        getline(infile, date, ',');
//        getline(infile, time, ',');
//
//        cout << "ip: " << ip << endl;
//        cout << "date: " << date << endl;
//        cout << "time: " << time << endl;
//        
//    }
//    infile.close();//closing teh file
//
//    
//    
//}
