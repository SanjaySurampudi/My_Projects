#include<bits/stdc++.h>
using namespace std;
char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int r,c;
void display(){
	
	cout<<"  "<<a[0][0]<<"   | "<<a[0][1]<<"   | "<<a[0][2]<<endl;
	cout<<"  ____|____"<<"_|_____"<<endl;
	cout<<"      |    "<<" |    "<<endl;
	cout<<"  "<<a[1][0]<<"   | "<<a[1][1]<<"   | "<<a[1][2]<<endl;
	cout<<"  ____|____"<<"_|_____"<<endl;
	cout<<"      |    "<<" |    "<<endl;
	cout<<"  "<<a[2][0]<<"   | "<<a[2][1]<<"   | "<<a[2][2]<<endl;

//	cout<<"      | "<<"    |    "<<endl;
//	cout<<"  ____|____"<<"_|____"<<endl;
//	cout<<"      |    "<<" |    "<<endl;
//	cout<<"      | "<<"    |    "<<endl;
//	cout<<"  ____|____"<<"_|____"<<endl;
//	cout<<"      |    "<<" |    "<<endl;
//	cout<<"      | "<<"    |    "<<endl;
	
}
void gridselection(){

	
	int grid;
	cout<<"SELECT GRID---->";
	cin>>grid;
	
	if(grid==1){
		r=0;
		c=0;
	}
	else if(grid==2){
		r=0;
		c=1;
	}
	else if(grid==3){
		r=0;
		c=2;
	}
	else if(grid==4){
		r=1;
		c=0;
	}
	else if(grid==5){
		r=1;
		c=1;
	}
	else if(grid==6){
		r=1;
		c=2;
	}
	else if(grid==7){
		r=2;
		c=0;
	}
	else if(grid==8){
		r=2;
		c=1;
	}
	else if(grid==9){
		r=2;
		c=2;
	}
}
void New(){
	char z='1';
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			a[i][j]=z;
			z++;
		}
	}
}
int decision(){
	int cnt=0;
	cout<<"THE GAME IS TIE"<<endl;
		 	cout<<"WANT TO PLAY AGAIN"<<endl;
		 	cout<<"1--->YES"<<endl;
		 	cout<<"2--->NO"<<endl;
		 	int n;
		 	cin>>n;
		 	if(n==1){
		 		New();
			 	cnt=0;
			 	display();
			 	cout<<endl;
			 }
			 else{
			 	return 0;
			 }
}
int win1(){
	if((a[0][0]==a[0][1] && a[0][0]==a[0][2]) || (a[0][0]==a[1][0] && a[0][0]==a[2][0]) || (a[0][0]==a[1][1] && a[0][0]==a[2][2]) || (a[0][1]==a[1][1] && a[0][1]==a[2][1]) ||  (a[1][0]==a[1][1] && a[1][0]==a[1][2]) ||
	 (a[0][2]==a[1][2] && a[0][2]==a[2][2]) || (a[2][0]==a[2][1] && a[2][0]==a[2][2]) || (a[0][2]==a[1][1] && a[0][2]==a[2][0])){
			
				cout<<"PLAYER-->1 WON THE GAME"<<endl;
				return 0;
			}
}
int win2(){
	if((a[0][0]==a[0][1] && a[0][0]==a[0][2]) || (a[0][0]==a[1][0] && a[0][0]==a[2][0]) || (a[0][0]==a[1][1] && a[0][0]==a[2][2]) || (a[0][1]==a[1][1] && a[0][1]==a[2][1]) || (a[1][0]==a[1][1] && a[1][0]==a[1][2]) || 
	 (a[0][2]==a[1][2] && a[0][2]==a[2][2]) || (a[2][0]==a[2][1] && a[2][0]==a[2][2]) || (a[0][2]==a[1][1] && a[0][2]==a[2][0])){
			cout<<"PLAYER-->2 WON THE GAME"<<endl;
			return 0;
		}
}
int main(){
	int cnt=0;
	display();
	cout<<endl;
	cout<<"PLAYER--->1 HAVE 1ST CHANCE"<<endl;
    cout<<"PLAYER--->2 HAVE 2ND CHANCE"<<endl;
	while((a[0][0]!=a[0][1] || a[0][0]!=a[0][2]) || (a[0][0]!=a[1][0] || a[0][0]!=a[2][0]) || (a[0][0]!=a[1][1] || a[0][0]!=a[2][2])){
	      	gridselection();
	      		cout<<"PLAYER--->1 HAVE 1ST CHANCE"<<endl;
                cout<<"PLAYER--->2 HAVE 2ND CHANCE"<<endl;
			  
	      	
	      	
			while(1){
				if(a[r][c]!='X' && a[r][c]!='O')break;
				
	     		cout<<"SELECT VALID GRID"<<endl;
				gridselection();
			 }
			 a[r][c]='X';
			 cnt++;
			 
				cout<<endl;
				display();
				cout<<endl;
			int r1=win1();
			if(r1==0)break;
			
			 if(cnt>=9){
			 	a[r][c]='X';
			 	display();
			 	int res=decision();
			 	if(res==0)break;
			 	cnt=0;
			 	continue;
			 }
		
     	gridselection();
     	while(1){
     		if(a[r][c]!='X' && a[r][c]!='O')break;
     		cout<<"SELECT VALID GRID"<<endl;
			gridselection();
		 }
		 a[r][c]='O';
		 cnt++;
		cout<<endl;
		display();
		cout<<endl;
		int r2=win2();
		if(r2==0)break;
	}
}
