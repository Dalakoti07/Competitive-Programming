// using sorting
int findLongestConseqSubseq(int arr[], int N){

  sort(arr,arr+N);
  int count=1,last=arr[0],maxLength=INT_MIN;
  for(int i=1;i<N;i++){
      if(arr[i]==arr[i-1]) // ignoring repeated elemets from subsequence
        continue;
      if((arr[i]==arr[i-1]+1) ){
          count++;
      }else{
            maxLength=max(maxLength,count);
            count=1;
      }
  }
  maxLength=max(maxLength,count);
  return maxLength;
}

// using hashing
int findLongestConseqSubseq(int arr[], int N){
  
  unordered_set<int> setty;
  for(int i=0;i<N;i++){
      setty.insert(arr[i]);
  }
  int maxLength=INT_MIN;
  for(int i=0;i<N;i++){
      if(setty.find(arr[i]-1)==setty.end()){
          int commingNumber=arr[i];
          while(setty.find( commingNumber)!=setty.end()){
              commingNumber++;
          }
          maxLength= max(maxLength,commingNumber-arr[i]);
      }
  }
  return maxLength;
}