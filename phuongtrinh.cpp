#include <bits/stdc++.h>

using namespace std;

int main(){
    double a,b,c,x,x1,x2;
    cin>>a>>b>>c;
    if (a==0&&b==0){
        if(c==0){
            cout<<" pt vo so nghiem";
        }
        else{
            cout<<" pt vo nghiem";
        }
    }
    else if(a==0){
        x=(-c)/b;
        if(x<0){
            cout<<" pt vo nghiem";
        }
        else if(x==0){
            cout<<"pt co 1 nghiem"<< " 0 ";
        }
        else{
            cout<<"pt co 2 nghiem"<<-sqrt(x)<<" "<<sqrt(x);
        }
    }
    else{
        double d=b*b-4*a*c;
        if(d<0){
            cout<<"pt vo nghiem";
        }
        else if(d==0){
            x=-b/(2*a);
            if(x<0){
                cout<<"pt vo nghiem";
            }
            else if(x==0){
                cout<<"pt co 1 nghiem"<<endl
                <<"0";
            }
            else{
                cout<<"pt co 2 nghiem"<<endl
                <<-sqrt(x)<<" "<<sqrt(x);
            }
        }
        else{
            x1=(-b-sqrt(d))/(2*a);
            x2=(-b+sqrt(d))/(2*a);
            if (x1<x2){
                if(x1<0&&x2<0){
                cout<<"pt vo nghiem";
                }
                else if((x1<0&&x2==0)||(x1==0&&x2==0)){
                cout<<"pt co 1 nghiem "<< "0";
                }
                else if(x1<0&&x2>0){
                cout<<"pt co 2 n"<<-sqrt(x2)<<" "<<sqrt(x2);
                }
                else if(x1==0&&x2>0){
                cout<<"pt co 3 nghiem\n"<<-sqrt(x2)<<" 0 "<<sqrt(x2);
                }
                else if(x1>0&&x2>0){
                cout<<"pt co 4 nghiem"<<-sqrt(x2)<<" "<<-sqrt(x1)<<" "<<sqrt(x1)<<" "<<sqrt(x2);
                }
            }
            else{
                if(x2<0&&x1<0){
                cout<<"pt vo nghiem";
                }
                else if((x2<0&&x1==0)||(x1==0&&x2==0)){
                cout<<"pt co 1 n" << "0";
                }
                else if(x2<0&&x1>0){
                cout<<"pt co 2 nghiem"<<-sqrt(x1)<<" "<<sqrt(x1);
                }
                else if(x2==0&&x1>0){
                cout<<"pt co 3 nghiem" << endl
                <<-sqrt(x1)<<" 0 "<<sqrt(x1);
                }
                else if(x1>0&&x2>0){
                cout<<"pt co 4 nghiem"
                <<-sqrt(x1)<<" "<<-sqrt(x2)<<" "<<sqrt(x2)<<" "<<sqrt(x1);
            }
            }
        }
    }
}
