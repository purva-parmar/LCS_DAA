class Solution {
    class costmatrix{
        int val;
        char dir;
        costmatrix(int val,char dir){
            this.val=val;
            this.dir=dir;
        }
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int m=text1.length(),n=text2.length();
        costmatrix[][] cost=new costmatrix[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    cost[i][j]=new costmatrix(0,'h');
                }
                else{
                    cost[i][j]=new costmatrix(0, 'h');
                    if(text1.charAt(i-1)!=text2.charAt(j-1)){
                        if(cost[i-1][j].val>=cost[i][j-1].val){
                        cost[i][j].val=cost[i-1][j].val;
                        cost[i][j].dir='u';
                        }
                        else{
                            cost[i][j].val=cost[i][j-1].val;
                            cost[i][j].dir='s';
                        }
                    }
                    else{
                        cost[i][j].val=cost[i-1][j-1].val+1;
                        cost[i][j].dir='d';
                    }
                }
            }
        }
        return (cost[m][n].val);
    }
}