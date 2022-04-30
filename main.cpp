#include <iostream>
#include <ctime>
using namespace std;
struct caracter
{
    string name;
    int hp=100,point=100;
};
struct enemy
{
    string name="Seyran";
    int hp=100,damage;
};
struct atacks
{
    string name;
    int point,damage;
};
struct health
{
    string name;
    int point,heal;
};
void printHP(enemy,caracter);
void PrintAtck(atacks [],health);
int main()
{
    caracter hero;
    enemy monster;
    atacks atck[3];
    health potion;
    int id,key;
    atck[0].name="sword storm"; atck[0].point=30; atck[0].damage=25;
    atck[1].name="fist of justice"; atck[1].point=10; atck[1].damage=15;
    atck[2].name="tiny gun"; atck[2].point=5; atck[2].damage=5;
    potion.name="Health potion";  potion.heal=20;  potion.point=5;
    
    srand(time(NULL));
    cout<<"name your hero: ";
    getline(cin, hero.name);
    cout<<"   "<<hero.name<<" "<<"Your game is start now"<<endl<<"enter 1 to continue"<<endl;
    cout<<"----------------------------------------------"<<endl;
    bool gameover = false;
    while(cin>>key){

        if(hero.hp==0 || hero.point<=4){
            gameover = true;
            break;
        }
        if(monster.hp==0)
            break;
        
        printHP(monster,hero);
        PrintAtck(atck,potion);
        cout<<"----------------------------------------------"<<endl;
        cout<<"enter the number of the attack you want"<<endl;
        cin>>id;
        if(atck[id-1].point>=hero.point){
            cout<<"----------------------------------------------"<<endl;
            cout<<"you don't have a enuogh P-point for that attack, please choose different attack"<<endl;;
            cout<<"----------------------------------------------"<<endl;
            while(cin>>id){
                if(atck[id-1].point<=hero.point)
                 break;
                else{
                    cout<<"----------------------------------------------"<<endl;
                    cout<<"you don't have a enuogh P-point for that attack, please choose different attack"<<endl;;
                    cout<<"----------------------------------------------"<<endl;
                }
            }
        }
         if(id==4){
            hero.hp=hero.hp+potion.heal;
            hero.point=hero.point-potion.point;
            cout<<"----------------------------------------------"<<endl;
            cout<<"you gain +"<<potion.heal<<" health and u lose -"<<potion.point<<" P-point"<<endl;
         }
         else{
            monster.hp=monster.hp-atck[id-1].damage;
            hero.point=hero.point-atck[id-1].point;
            cout<<"----------------------------------------------"<<endl;
            cout<<"you have done "<<atck[id-1].damage<<" damage to the monster and u lose -"<<atck[id-1].point<<" P-point"<<endl;
         }
        monster.damage = rand()%(11) + 15;
        hero.hp=hero.hp-monster.damage;
        cout<<"----------------------------------------------"<<endl;
        cout<<"monster have done -"<<monster.damage<<" damag to you"<<endl;
        
        cout<<"----------------------------------------------"<<endl;
        cout<<"enter 1 to continue"<<endl;
        cout<<"----------------------------------------------"<<endl;
    }
    if(gameover==false){
        cout<<"----------------------------------------------"<<endl;
        cout<<"congratulations! you are the winner"<<endl;
        cout<<"----------------------------------------------"<<endl;
        printHP(monster,hero);
    }
    else{
        cout<<"----------------------------------------------"<<endl;
        cout<<"oh no! you lose the game"<<endl;
        cout<<"----------------------------------------------"<<endl;
        printHP(monster,hero);
    }
    return 0;
}
void PrintAtck(atacks atck[],health potion){
    for(int i=0;i<3;i++)
     cout<<i+1<<". "<<atck[i].name<<" | "<<"damage: "<<atck[i].damage<<" | "<<"P-point: "<<atck[i].point<<endl;
     
    cout<<"4. "<<potion.name<<" | "<<"health: "<<potion.heal<<" | "<<"P-point: "<<potion.point<<endl;
}
void printHP(enemy mosnter,caracter hero){
    cout<<"you: "<<"health: "<<hero.hp<<" | "<<"power point: "<<hero.point<<endl;
    cout<<"monster: "<<"health: "<<mosnter.hp<<endl;
    cout<<"----------------------------------------------"<<endl;
}