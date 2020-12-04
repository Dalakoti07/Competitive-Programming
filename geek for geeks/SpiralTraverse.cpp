vector<int> spirallyTraverse(vector<vector<int> > matrix, int m, int n){
    int i,k=0,l=0;
    vector<int> answer;
    /*
        i=iterator
        k=starting row
        l=starting col
        m=end row
        n=end col
    */
    while(k<m and l<n){
        //print top row
        for(i=l;i<n;i++)
            answer.push_back(matrix[k][i]);
        k++;
        // print last col
        for(i=k;i<m;i++)
            answer.push_back(matrix[i][n-1]);
        n--;
        // print bottom row
        if(k<m){
            for(i=n-1;i>=l;i--)
                answer.push_back(matrix[m-1][i]);
            m--;
        }
        // print first col
        if(l<n){
            for(i=m-1;i>=k;i--)
                answer.push_back(matrix[i][l]);
            l++;
        }
    }
    return answer;
    }