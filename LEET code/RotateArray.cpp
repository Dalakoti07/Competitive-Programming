void rotate(vector<int>& nums, int k) {
	if (nums.empty())
		return;
	std::rotate(nums.rbegin(), nums.rbegin() + k % nums.size(), nums.rend());
}   