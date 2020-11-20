//find common elems in three arrays
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            int i=0,j=0,k=0;
            set<int> commonElems;
            while(i<n1 and j<n2 and k<n3){
                if(A[i]==B[j] and B[j]==C[k])
                    commonElems.insert(A[i]);
                if(A[i]<=B[j] and A[i]<=C[k])
                    i++;
                else if(B[j]<=A[i] and B[j]<=C[k])
                    j++;
                else if(C[k]<=A[i] and C[k]<=B[j])
                    k++;
            }
            return vector<int>(commonElems.begin(),commonElems.end());
        }
};