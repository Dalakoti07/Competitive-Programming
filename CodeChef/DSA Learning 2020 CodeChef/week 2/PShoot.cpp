#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string goals;
        cin>>goals;
        int teamAGoals=0,teamBGoals=0;
        int teamAReaminingOpportunitiesForGoal=n,teamBReaminingOpportunitiesForGoal=n;
        int ans=-1;
        for(int i=0,j=1;j<goals.length();i=i+2,j=j+2){
            if(goals[i]=='1') teamAGoals++;
            teamAReaminingOpportunitiesForGoal--;
            // cout<<"Goal made by A: teamA: "<<teamAGoals<<" teamAOpp: "<<teamAReaminingOpportunitiesForGoal<<" teamB: "<<teamBGoals<<" teamBOpp: "<<teamBReaminingOpportunitiesForGoal<<endl;
            if(teamAGoals> teamBGoals+teamBReaminingOpportunitiesForGoal){
                if(teamAGoals>teamBGoals){
                    ans=i+1;
                    break;
                }
            }
            if(teamBGoals> teamAGoals+teamAReaminingOpportunitiesForGoal){
                if(teamBGoals>teamAGoals){
                    ans=i+1;
                    break;
                }
            }
            if(goals[j]=='1') teamBGoals++;
            teamBReaminingOpportunitiesForGoal--;
            // cout<<"Goal made by B: teamA: "<<teamAGoals<<" teamAOpp: "<<teamAReaminingOpportunitiesForGoal<<" teamB: "<<teamBGoals<<" teamBOpp: "<<teamBReaminingOpportunitiesForGoal<<endl;
            if(teamBGoals> teamAGoals+teamAReaminingOpportunitiesForGoal){
                if(teamBGoals>teamAGoals){
                    ans=j+1;
                    break;
                }
            }
            if(teamAGoals> teamBGoals+teamBReaminingOpportunitiesForGoal){
                if(teamAGoals>teamBGoals){
                    ans=j+1;
                    break;
                }
            }
        }
        if(ans==-1){
            cout<<goals.length()<<endl;
        }else{
            cout<<ans<<endl;
        }
        // cout<<"next\n"<<endl;
    }
}