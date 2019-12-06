#include<iostream>
#include<string.h>
#include<map>
#include<vector>
#include<algorithm>
/*
 *黄海浪 9181040G0818
 *2019.12.06
 *第 20 次作业
 */
using namespace std;

struct nxss{
    unsigned int times;
    char c[30];
};
int getRev(char a[]){
    int s=0;
    unsigned long len = strlen(a);
    for(int i=0;i<len;++i){
        for(int j=i+1;j<len;++j){
            if(a[i]-a[j]>0){
                ++s;
            }
        }
    }
    return s;
}
void getTimes(nxss *nxs,int n){
    for(int i=0;i<=n;++i){
        nxs[i].times = getRev(nxs[i].c);
    }
}
bool cmp(nxss &t1,nxss &t2){
    return t1.times<t2.times;
}

bool cmp2(char *t1,char *t2){
    unsigned long len1 = strlen(t1);
    unsigned long len2 = strlen(t2);
    unsigned long len = len1<len2?len1:len2;
    for(int i = 0;i<len;++i){
        if(t1[i] != t2[i]) return t1[i]<t2[i];
    }
    return len1<len2;
}

bool cmp3(pair<string ,int> &t1,pair<string ,int> &t2){
    return t1.second>t2.second;
}

int main(){
    {//(6)
        int MAX;
        cin>>MAX;
        cin.get();
        nxss *nxs = new nxss[MAX];
        int n=0;
        while(cin.getline(nxs[n].c, 21)&&nxs[n].c[0]!='\0'&&n<MAX-1){
            ++n;
        }
        if(nxs[n].c[0]=='\0'){
            --n;
        }
        getTimes(nxs,n);
        sort(nxs,nxs+n+1,cmp);
        for(int i=0;i<=n;++i){
            cout<<nxs[i].c<<" "<<nxs[i].times<<endl;
        }
    }
    {//T4
        int n;
        cin>>n;
        cin.get();
        char ** strs = new char * [n];//n个字符串
        for(int i=0;i<n;++i){
            char tmp;
            char *str = nullptr;
            while(cin.get(tmp)){
                if( tmp=='\0' || tmp=='\n'){
                    break;
                }
                char *data;
                if(!str){
                    data = new char [2];
                    data[0] = tmp;
                    data[1] = '\0';
                }else{
                    unsigned long len = strlen(str);
                    data =new char [len+2];
                    strcpy(data,str);
                    data[len] = tmp;
                    data[len+1] = '\0';
                }
                //删去old空间
                delete [] str;
                str = data;
            }
            strs[i] = str;
        }
        sort(strs,strs+n, cmp2);
        cout<<endl;
        map< string,int > mp;
        for(int i=0;i<n;++i){
            cout<<strs[i]<<" ";
            ++mp[strs[i]];
            delete [] strs[i];
        }
        delete [] strs;
        cout<<endl;
        vector< pair<string,int> > vec(mp.begin(),mp.end());
        sort(vec.begin(), vec.end(), cmp3);
        while(vec.begin()!=vec.end()){
            cout<<vec.begin()->first<<" "<<vec.begin()->second<<endl;
            vec.erase(vec.begin());
        }
    }
    return 0;
}
