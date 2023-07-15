#include<bits/stdc++.h>
using namespace std;
double lemda=1.5418;

// function  for converting degree to radian

double radian(double degree){
    return (degree/180.0)*3.14159;
}


// material class
class material{
    public:
    vector<double> angle;
    vector<double> dist;
    material(){}
    material(vector<double> angle,int i=0){
        this->angle=angle;
        
    }
    //function for calculatin of dist vector;
   void dis();
    void printdistofplane();
};
void material:: dis(){
       for(auto it:angle){
           dist.push_back((lemda/2)/sin(radian(it)));
       }
        
}
void material::printdistofplane(){
        dis();
        for(int i=0;i<angle.size();i++){
            cout<<">>>>> for angle "<<angle[i]<<"distance d->"<<dist[i]<<'\n';
        }
    }


class lattice : public material
{
public:
    string type="";
    vector<int> sequence;
    vector<string> hkl;
    
    lattice(vector<double> angle)
    {
      this->angle=angle;
    }
    ~lattice();
    vector<double> sinsq();
    string  type_of_lat();
    void seq();
    void hkllat();

};


// lattice::lattice(vector<double> angle)
// {
//     this->angle=angle;
// }

lattice::~lattice(){}
vector<double> lattice::sinsq(){
    vector<double> ans;
    for(auto it: angle){
        double a =sin(radian(it))*sin(radian(it));
        ans.push_back(a);
    }
    return ans;
}
string lattice::type_of_lat(){
    if (sequence.size()==0)return ""; //problem occurs here---------------------------------
    if(sequence[0]==3){
        return type="FCC";
    }
    else if(sequence[6]==8){
        return type = "SC";
    }
    return type="BCC";
   
}
void lattice::seq(){
    vector<double> ang =angle;
    vector<double> sinsq1 = sinsq();
    vector<int> sequence_vect;
    
    double a =sinsq1[0];
    if(((sinsq1[1]/sinsq1[0])+0.25 )/1==2){
        for(auto it:sinsq1){
            sequence_vect.push_back((int)(((it/a)+0.25)/(1)));
        }
    }
    else{
        for(auto it:sinsq1){
            sequence_vect.push_back((int)((((it/a)*3)+0.25)/1));
        }

    }
    sequence=sequence_vect;
    return ;
}

void lattice::hkllat(){
    vector<string> vect;
    for(auto it:sequence){
         switch (it)
         { 
         case 0:
            vect.push_back("000");
            break;
         case 1:
            vect.push_back("100");
            break;
         case 2:
            vect.push_back("110");
            break;
         case 3:
            vect.push_back("111");
            break;
         case 4:
            vect.push_back("200");
            break;
        case 5:
            vect.push_back("120");
            break;
         case 6:
            vect.push_back("211");
            break;
         case 8:
            vect.push_back("220");
            break;
         case 11:
            vect.push_back("311");
            break;
         case 12:
            vect.push_back("222");

         
         default:
            vect.push_back("###");
            break;
         }
    }
    hkl=vect;
    return ;
}
// function for calculating lattice property

void latticeproperty(){
    cout<<">>>>> please enter  7 angels in degree"<<'\n';
    vector<double> angle;
    for(int i=0;i<7;i++){
        double a ;
        cout<<">>>>>";
        cin>>a;
        cout<<'\n';
        angle.push_back(a);
    }
    lattice l(angle);
    l.dis();
    // l.sinsq();   ------------------>
    l.seq();
    l.hkllat();
    l.type_of_lat();
    cout<<">>>>> type of given lattice is ==>"<<l.type<<'\n';//problem-------------------detected


    for(int i=0;i<6;i++){
        cout<<">>>>> for angle : "<<l.angle[i]<< "dist b/w plane :"<<l.dist[i];
        cout<<l.sequence[i];
        cout<<"plane  is : "<<l.hkl[i]<<'\n';
        // ---------------------------------------------------------------------------------------------------- problem detected
    }

    
}





// function for taking input of solid angle
void takesolidangle(){
    cout<<">>>>> please enter angle thita in degree one by one"<<'\n';
     
    vector<double> angle;
    cout<<">>>>> Enter No of angle"<<'\n';
    int a;
    cin>>a;
    cout<< ">>>>> enter angle"<<'\n';
    int i=0;
    while(i<a){
        double ang;
        cin>>ang;
        angle.push_back(ang);
        i++;
    }
    material m1(angle);
    m1.printdistofplane();
    
}

int main() {
    cout<<">>>>>welcome to XRD calculation "<<'\n';
    cout<<">>>>>if you have list of angle for calculation of dist--->enter -->solid_angle"<<'\n';
    cout<<">>>>> for lattice calculation -->enter-->lattice"<<'\n';
    cout<<">>>>>if you want to stop ---> enter --->stop "<<'\n';
    
    int i=0;
    while(i<100){
        string s;
        cin>>s;
        if(s=="stop")break;
        else if(s=="solid_angle"){
            takesolidangle();
        }
        else if(s=="lattice"){
            latticeproperty();
        }
        i++;
    }
    
    return 0;
}