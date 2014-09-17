#include <iostream>
#include <sstream>
#include <iomanip>

#include "crypto.hpp"

using namespace std;
using namespace SimpleWeb;

template<class type>
string to_hex_string(const type& chars) {
    stringstream hex_ss;
    hex_ss.fill('0');
    for (auto c : chars) {
        hex_ss << setw(2) << hex << (int) (unsigned char) c;
    }
    return hex_ss.str();
}

bool check(string pw, string hashed_pw, string salt) {
    string sha = salt + pw;
    for (size_t c = 0; c < 1000; c++) {
        Crypto::SHA512(sha, sha);
    }
    if (to_hex_string(sha) == hashed_pw) {
        
        return true;
    }
    return false;
}


bool combinations(int pos, string& pw, string chars, int pwSize, string hashed_pw, string salt){
  for (auto c1: chars) {
    pw.resize(pwSize+1);   
    pw[pos] = c1;
    if(check(pw, hashed_pw, salt)){
        return true;
    }
        if(pos < pwSize) {
          if(combinations(pos+1, pw, chars, pwSize, hashed_pw, salt)){
            return true;
          }
        }
      }
    return false;
  }

int main() {
  string password="bg";
  string salt="dette er et salt";
  /*//int maxlength = 30;
  string sha=salt+password;
  for(size_t c=0;c<1000;c++) {
    Crypto::SHA512(sha, sha); 
  }
  string hashed_pw=to_hex_string(sha);
   */
  //setter Øvingens hashed_pw
  string hashed_pw = "1cb60f4fcd7c73748ec313a485f8435b70bff999a8f2067510b43b78438b1cff54309738b9b6e02ff3f5a267b4e0f2d2da7bc7ec2326c3b144f7e4ad55150fd5";    
  string chars="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  string pw;
  int i = 0;
  cout<<endl;
  do{   
      cout << "PW length : " << i+1 << endl;
        if(combinations(0, pw, chars, i, hashed_pw, salt)){
          cout<<"************************"<<endl<<"       PW : "<<pw<<endl<<"************************"<<endl<<endl;
          return 0; //return 0 for å avslutter den evige løkka når den finner passordet
      } 
      i++; 
  }while(true);

  return 0;
}

