class Solution {
public:
    //this splits a versiom string 
    vector<int> helper(string& ver){
        vector<int>rev;
        stringstream ss(ver);
        string item;

        while(getline(ss,item,'.')){
            rev.push_back(stoi(item));
        }

        return rev;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1= helper(version1);
        vector<int> v2= helper(version2);
        int s= max(v1.size(),v2.size());

        for(int i=0;i<s;i++){
            int n1=i<v1.size()?v1[i]:0;
            int n2=i<v2.size()?v2[i]:0;

            if(n1<n2)return -1;
            if(n1>n2)return 1;
        }

        return 0;
                                    
    }
};