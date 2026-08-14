class Node{
public:
    int maxLen;
    char leftMostChar;
    char rightMostChar;
    int prefixLen;
    int suffixLen;

    Node(){}
    Node(int maxLen, char left, char right, int prefixLen, int suffixLen){
        this->maxLen = maxLen;
        this->leftMostChar = left;
        this->rightMostChar= right;
        this->prefixLen = prefixLen;
        this->suffixLen = suffixLen;
    }
};

class Solution {

private:

Node* merge(Node* leftChild, Node* rightChild, int leftLen, int rightLen){

    Node* node = new Node();
    node->maxLen = max(leftChild->maxLen,rightChild->maxLen);
    if(leftChild->rightMostChar == rightChild->leftMostChar){
        node->maxLen = max(node->maxLen,leftChild->suffixLen + rightChild->prefixLen);
    }
    node->leftMostChar = leftChild->leftMostChar;
    node->rightMostChar = rightChild->rightMostChar;

    node->prefixLen = leftChild->prefixLen;
    if(leftChild->rightMostChar == rightChild->leftMostChar 
                        && leftChild->prefixLen == leftLen){
        node->prefixLen += rightChild->prefixLen; 
    } 

    node->suffixLen = rightChild->suffixLen;
    if(leftChild->rightMostChar == rightChild->leftMostChar 
                        && rightChild->suffixLen == rightLen){
        node->suffixLen += leftChild->suffixLen;
    }

    return node;
}



void buildSegmentTree(string &s,vector<Node*> &segmentArr, int index, int low, int high){
    
    if(low==high){
        Node* node = new Node(1,s[low],s[low],1,1);
        segmentArr[index] = node;
        return;
    }

    int mid = low + (high-low)/2;
    int leftChild = 2*index+1, rightChild=2*index+2;

    buildSegmentTree(s,segmentArr,leftChild,low,mid);
    buildSegmentTree(s,segmentArr,rightChild,mid+1,high);

    segmentArr[index] = merge(segmentArr[leftChild],segmentArr[rightChild],mid-low+1,high-mid);
}

void pointUpdate(vector<Node*> &segmentArr, int targetIndex, char ch, int index, int low, int high){
    if(low==high){
        segmentArr[index]->leftMostChar = ch;
        segmentArr[index]->rightMostChar = ch;
        return;
    }


    int mid = low + (high-low)/2;
    int leftChild = 2*index+1, rightChild=2*index+2;

    if(targetIndex<=mid) pointUpdate(segmentArr, targetIndex, ch, leftChild, low, mid);
    else pointUpdate(segmentArr, targetIndex, ch, rightChild, mid+1, high);


    segmentArr[index] = merge(segmentArr[leftChild],segmentArr[rightChild],mid-low+1,high-mid);
}

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int q = queryIndices.size();

        vector<Node*> segmentArr(4*n);
        buildSegmentTree(s,segmentArr,0,0,n-1);

        vector<int> ans;
        for(int i=0;i<q;i++){
           char ch = queryCharacters[i];
           int targetIndex = queryIndices[i];

           pointUpdate(segmentArr,targetIndex,ch,0,0,n-1);
           ans.push_back(segmentArr[0]->maxLen); 
        }

        return ans;
    }
};