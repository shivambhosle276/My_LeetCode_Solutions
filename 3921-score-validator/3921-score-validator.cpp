class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {

        int score = 0;
        int counter = 0;

        for(int i = 0; i < events.size(); i++)
        {
            // stop if counter becomes 10
            if(counter == 10)
                break;

            if(events[i] == "0" || events[i] == "1" ||
               events[i] == "2" || events[i] == "3" ||
               events[i] == "4" || events[i] == "6")
            {
                score += stoi(events[i]);
            }

            else if(events[i] == "W")
            {
                counter++;
            }

            else if(events[i] == "WD")
            {
                score++;
            }

            else if(events[i] == "NB")
            {
                score++;
            }
        }

        return {score, counter};
    }
};