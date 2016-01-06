#include <cstring>
#include <iostream>
#include <conio.h>
using namespace std;
namespace trie
{

template<class T,size_t CHILD_MAX>
/*
Parameter T:Type of reserved data.
ParameterCHILD_MAX:Sizeofarryofpointerstochildnode.
*/
struct nod
{
    T reserved;
    nod<T,CHILD_MAX> *child[CHILD_MAX];
    nod()
    {
        memset(this,0,sizeof*this);
    }
    ~nod()
    {
        for(unsigned i=0;i<CHILD_MAX;i++)
            delete child[i];
    }
    void Traversal(char *str,unsigned index)
    {
        unsigned i;
        for(i=0;i<index;i++)
            cout<<str[i];
        cout<<'\t'<<reserved<<endl;
        for(i=0;i<CHILD_MAX;i++)
        {
            if(child[i])
            {
                str[index]=i;
                child[i]->Traversal(str,index+1);
            }
        }
        return;
    }
};

template<class T,size_t CHILD_MAX=127>
/*
ParameterT:Typeofreserveddata.
ParameterCHILD_MAX:Sizeofarryofpointerstochildnode.
*/
class trie
{
private:
    nod<T,CHILD_MAX>root;
public:
    nod<T,CHILD_MAX>*AddStr(char*str);
    nod<T,CHILD_MAX>*FindStr(char*str);
    boolDeleteStr(char*str);
    voidTraversal()
    {
        charstr[100];
        root.Traversal(str,0);
    }
};

template<classT,size_tCHILD_MAX>
nod<T,CHILD_MAX>*trie<T,CHILD_MAX>::AddStr(char*str)
{
    nod<T,CHILD_MAX>*now=&root;
    do
    {
        if(now->child[*str]==NULL)
            now->child[*str]=newnod<T,CHILD_MAX>;
        now=now->child[*str];
    }while(*(++str)!='\0');
    returnnow;
}

template<classT,size_tCHILD_MAX>
nod<T,CHILD_MAX>*trie<T,CHILD_MAX>::FindStr(char*str)
{
    nod<T,CHILD_MAX>*now=&root;
    do
    {
        if(now->child[*str]==NULL)
            returnNULL;
        now=now->child[*str];
    }while(*(++str)!='\0');
    returnnow;
}

template<classT,size_tCHILD_MAX>
booltrie<T,CHILD_MAX>::DeleteStr(char*str)
{
    nod<T,CHILD_MAX>**nods=newnod<T,CHILD_MAX>*[strlen(str)];
    intsnods=1;
    nod<T,CHILD_MAX>*now=&root;
    nods[0]=&root;
    do
    {
        if(now->child[*str]==NULL)
            returnfalse;
        nods[snods++]=now=now->child[*str];
    }while(*(++str)!='\0');
    snods--;
    while(snods>0)
    {
        for(unsignedi=0;i<CHILD_MAX;i++)
            if(nods[snods]->child[i]!=NULL)
                returntrue;
            deletenods[snods];
            nods[--snods]->child[*(--str)]=NULL;
        }
        returntrue;
    }
}
intmain()
{
//TestProgram
    trie::trie<int>tree;
    while(1)
    {
        cout<<"1foraddastring"<<endl;
        cout<<"2forfindastring"<<endl;
        cout<<"3fordeleteastring"<<endl;
        cout<<"4fortraversal"<<endl;
        cout<<"5forexit"<<endl;
        charstr[100];
        switch(getch())
        {
            case'1':
            cin.getline(str,100);
            cout<<"Thisstinghasexistedfor"<<tree.AddStr(str)->reserved++<<"times."<<endl;
            break;
            case'2':
            cin.getline(str,100);
            trie::nod<int,127>*find;
            find=tree.FindStr(str);
            if(!find)
                cout<<"Nofound."<<endl;
            else
                cout<<"Thisstinghasexistedfor"<<find->reserved<<"times."<<endl;
            break;
            case'3':
            cin.getline(str,100);
            cout<<"Theactionis"<<(tree.DeleteStr(str)?"Successful.":"Unsuccessful.")<<endl;
            break;
            case'4':
            tree.Traversal();
            break;
            case'5':
            return0;
        }
    }
    return0;
}