class Solution
{
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        int n = people.size();

        if (n == 1)
        {
            return 1;
        }

        int ans = 0;

        int heavy = n - 1;
        int light = 0;

        sort(people.begin(), people.end());

        while (light <= heavy)
        {
            
            ans++;

            
            
            if (people[light] + people[heavy] <= limit)
            {
                light++;
                heavy--;
            }
            else
            {
                
                heavy--;
            }
        }

        return ans;
    }
};