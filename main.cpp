#include<iostream>
#include <fstream>
#include <chrono>
#include <Windows.h>
#include <unistd.h>
using namespace std;

int main() {   
     
  string filename, textinfile;
  
  fstream file_out;

  int amount;

  clock_t start, end;
  
  cout << "Name of Files?\n";
  getline(cin, filename);

  cout << "amount of files?\n";
  cin >> amount;
  
  cin.ignore();
  
  cout << "text inside of files?\n";
  getline(cin, textinfile);

  start = clock();
  
  for (int i = 1; i <= amount; i = i + 1)
    {
    
    file_out.open((filename + "_" + to_string(i) + ".txt"), std::ios_base::out);
    
    if (!file_out.is_open()) {
      cout << "failed to open " << filename << '\n'; }
    
    else {
      file_out << textinfile << endl;
      file_out.close();}
    
  }
  end = clock();
  
  cout << "done\n\n";
  cout << "took " << float(end - start) << " miliseconds to finish\n";
  cout << "quitting in 5 seconds...";
  
  sleep(5);
  
  return EXIT_SUCCESS;
  }
