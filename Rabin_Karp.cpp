/*Implementation of Rabin Karp Algorithm*/

#include<bits/stdc++.h>
using namespace std;

//hashing function
int hashFunction(string p){
	
	int m=p.size();
	int hash=0,b=1;
	for(int i=m-1;i>=0;i--){
		hash+=(b*(p[i]-'a'+1))%INT_MAX;
		b=(b*26)%INT_MAX;
	}
	cout<<hash<<endl;
	return hash;
}

//Rabin Karp function
void rabinKarp(string t,string p){
	
	int patternHash=hashFunction(p);
	int n=t.size(),m=p.size();
	int hash=hashFunction(t.substr(0,m));
	
	for(int i=1;i<n-m;i++){
		if(hash==patternHash){
			cout<<"Pattern found at shift "<<i-1<<endl;
		}
		hash-=(int(pow(26,m-1))%INT_MAX*(p[i-1]-'a'+1)%INT_MAX)%INT_MAX;
		hash=(hash*26)%INT_MAX;
		hash+=(p[i+m-1]-'a'+1);
		
		if(hash<0)	hash+=INT_MAX;
		cout<<i<<" "<<hash<<endl;
	}
	return;
	
}

int main(){
	
	string t="ababababa",p="aba";
	rabinKarp(t,p);
	//cout<<"hell";
	
	return 0;
}
