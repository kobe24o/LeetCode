class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
       sort(deck.begin(), deck.end());
       deque<int> result;
       for(int i = deck.size()-1; i >= 0; --i) 
       {
       		if(!result.empty())
       		{
       			result.push_front(result.back());
       			result.pop_back();
       		}
       		result.push_front(deck[i]);
       }
       vector<int> finalresult(result.begin(), result.end());
       return finalresult; 
    }
};