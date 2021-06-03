#include <vector>
using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
	//brute force O(n2) but this solution is O(n)
	int n=distances.size();
	int milesRemaining=0;
	int indexOfStaringCity=0;
	int milesRemainingAtStartingCity=0;
	
	for(int i=1;i<n;i++){
		int distanceFromPreviousCity=distances[i-1];
		int fuelFromPreviousCity=fuel[i-1];
		milesRemaining+= fuelFromPreviousCity*mpg - (distanceFromPreviousCity);
		
		if(milesRemaining<milesRemainingAtStartingCity){
			milesRemainingAtStartingCity=milesRemaining;
			indexOfStaringCity=i;
		}
	}
	
    return indexOfStaringCity;
}
