class Solution {
public:
    string Bruteforce(string& title){
        queue<string> store;
        int start = 0, i=0;
        for(i=0; i<title.size(); i++){
            if(title[i] == ' '){
                store.push(title.substr(start, i-start));
                start = i+1;
            }
        }
        store.push(title.substr(start, i-start));
        title = "";

        while(!store.empty()){
            string temp = store.front();
            store.pop();
            cout << temp << "->" << temp.size() << endl;
            if(temp.size() <= 2){
                for(int i=0; i<temp.size(); i++)
                    temp[i] = tolower(temp[i]);
            }else{
                for(int i=1; i<temp.size(); i++)
                    temp[i] = tolower(temp[i]);
                temp[0] = toupper(temp[0]);
            }
            title += (temp + ' ');
        }
        title.pop_back();
        return title;
    }

    string capitalizeTitle(string title) {

        // return Bruteforce(title);

        int start=0, i=0;
        for(i=0; i<title.size(); i++){
            title[i] = tolower(title[i]);
            
            if(title[i] == ' '){
                if(i-start>2)
                    title[start] = toupper(title[start]);
                    
                start = i+1;
            }
        }

        if(i-start>2)
            title[start] = toupper(title[start]);
                
        return title;   

    }
};