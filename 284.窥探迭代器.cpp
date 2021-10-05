/*
 * @lc app=leetcode.cn id=284 lang=cpp
 *
 * [284] 窥探迭代器
 */

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
	int index;
	vector<int> vec;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    vec=nums;
		index=0;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return vec[index];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(hasNext())return vec[index++];
		return -1;
	}
	
	bool hasNext() const {
		if(index<vec.size())return true;
		return false;
	}
};
// @lc code=end

