#include<iostream>
#include <fstream>
#include <chrono>
#include <Windows.h>
#include <unistd.h>
using namespace std;

void clearscrn(){

  system("cls");
}

int main() {   
     
  string filename, textinfile;
  
  fstream file_out;

  int amount;
  float perc,curperc;
  clock_t start, end;
  
  cout << "Name of Files?\n";
  getline(cin, filename);

  cout << "amount of files?\n";
  cin >> amount;
  
  cin.ignore();
  
  cout << "text inside of files?\n";
  getline(cin, textinfile);
  
  clearscrn();

  start = clock();
  
  for (int i = 1; i <= amount; i = i + 1)
    {

    file_out.open((filename + "_" + to_string(i) + ".txt"), std::ios_base::out);
    
    if (!file_out.is_open()) {
      cout << "failed to open " << filename << '\n'; }
    
    else {
      file_out << textinfile << endl;
      file_out.close();}

    if(i%100== 0){
    float curperc = double(i) / double(amount) * 100;
    clearscrn();
    cout  <<curperc << " %\n";
    }
    
    
  }
  end = clock();
  clearscrn();
  cout << "done\n\n";
  cout << "took " << float(end - start) << " miliseconds to finish\n";
  cout << "quitting in 5 seconds...";
  
  sleep(5);
  
  return EXIT_SUCCESS;
  }
