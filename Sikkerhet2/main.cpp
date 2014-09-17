#include <iostream>
#include <random>


using namespace std;

string decrypt (string str, string key);


int main() {
   
  string key = "Dette er en noekkel";
  string crypt = "114b70745a521c57371f7a245d6440662d49";
  
  string message = decrypt(crypt,key);
  cout<<message<<endl;
  
    return 0;
}

string decrypt(string str, string key){
    seed_seq seed(key.begin(), key.end());
     minstd_rand0 generator(seed);
     uniform_int_distribution<char> dist;
     string message;
     string strByte;
     int a;
     char b;
     
     for (int i = 0; i < str.length(); i+=2) {
         a = dist(generator);
         strByte = str[i];
         strByte += str[i+1];
         b = (char)stoi(strByte.c_str(),NULL,16);
         message+=b^a;        

    }
     return message;

}

