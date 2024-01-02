#include<stdio.h>
int main(){
int k;
scanf("%d",&k);
for(int caseNum=0;caseNum<k;caseNum++){
    int me,lift;
    scanf("%d %d",&me,&lift);
    if(me<=lift){
       int time=19+(lift*4);
    printf("Case %d: %d\n",caseNum+1,time);
    }
    else{
        int total_floor=(me-lift)+me;
        int time=19+(total_floor*4);
        printf("Case %d: %d\n",caseNum+1,time);
    }
}
  return 0;
}
