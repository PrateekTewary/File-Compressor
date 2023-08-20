#include<bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    unsigned freq;
    string code;
    Node *left, *right;

    Node() {
        left = right = NULL;
    }
};

class huffman {
    private:
        vector <Node*> arr;

        fstream inFile, outFile;

        string inFileName, outFileName;

        Node *root;

        class Compare {
            public:
                bool operator() (Node* l, Node* r)
                {
                    return l->freq > r->freq;
                }
        };

        priority_queue <Node*, vector<Node*>, Compare> minHeap;

        //Initializing a vector of tree nodes representing character's ascii value and initializing its frequency with 0
        void createArr();

        //Traversing the constructed tree to generate huffman codes of each present character
        void traverse(Node*, string);

        //Function to convert binary string to its equivalent decimal value
        int binToDec(string);

        //Function to convert a decimal number to its equivalent binary string
        string decToBin(int);

        //Reconstructing the Huffman tree while Decoding the file
        void buildTree(char, string&);

        //Creating Min Heap of Nodes by frequency of characters in the input file
        void createMinHeap();

        //Constructing the Huffman tree
        void createTree();

        //Generating Huffman codes
        void createCodes();

        //Saving Huffman Encoded File
        void saveEncodedFile();

        //Saving Decoded File to obtain the original File
        void saveDecodedFile();

        //Reading the file to reconstruct the Huffman tree
        void getTree();

    public:
        //Constructor
        huffman(string inFileName, string outFileName)
        {
            this->inFileName = inFileName;
            this->outFileName = outFileName;
            createArr();
        }
        //Compressing input file
        void compress();
        //Decrompressing input file
        void decompress();
};

void huffman::createArr() {
    for (int i = 0; i < 128; i++) {
        arr.push_back(new Node());
        arr[i]->data = i;
        arr[i]->freq = 0;
    }
}

void huffman::traverse(Node* r, string str) {
    if (r->left == NULL && r->right == NULL) {
        r->code = str;
        return;
    }

    traverse(r->left, str + '0');
    traverse(r->right, str + '1');
}

void huffman::createMinHeap() {
    char id;
    inFile.open(inFileName, ios::in);
    inFile.get(id);
    //Incrementing frequency of characters that appear in the input file
    while (!inFile.eof()) {
        arr[id]->freq++;
        inFile.get(id);
    }
    inFile.close();
    //Pushing the Nodes which appear in the file into the priority queue (Min Heap)
    for (int i = 0; i < 128; i++) {
        if (arr[i]->freq > 0) {
            minHeap.push(arr[i]);
        }
    }
}
void huffman::createTree() {
    //Creating Huffman Tree with the Min Heap created earlier
    Node *left, *right;
    priority_queue <Node*, vector<Node*>, Compare> tempPQ(minHeap);
    while (tempPQ.size() != 1)
    {
        left = tempPQ.top();
        tempPQ.pop();

        right = tempPQ.top();
        tempPQ.pop();

        root = new Node();
        root->freq = left->freq + right->freq;

        root->left = left;
        root->right = right;
        tempPQ.push(root);
    }
}
void huffman::createCodes() {
    //Traversing the Huffman Tree and assigning specific codes to each character
    traverse(root, "");
}

void huffman::saveEncodedFile() {
    //Saving encoded (.huf) file
    inFile.open(inFileName, ios::in);
    outFile.open(outFileName, ios::out | ios::binary);
    string in = "";
    string s = "";
    char id;

    //Saving the meta data (huffman tree)
    in += (char)minHeap.size();
    priority_queue <Node*, vector<Node*>, Compare> tempPQ(minHeap);
    while (!tempPQ.empty()) {
        Node* curr = tempPQ.top();
        in += curr->data;
        //Saving 16 decimal values representing code of curr->data
        s.assign(127 - curr->code.length(), '0');
        s += '1';
        s += curr->code;
        //Saving decimal values of every 8-bit binary code
        in += (char)binToDec(s.substr(0, 8));
        for (int i = 0; i < 15; i++) {
            s = s.substr(8);
            in += (char)binToDec(s.substr(0, 8));
        }
        tempPQ.pop();
    }
    s.clear();

    //Saving codes of every charachter appearing in the input file
    inFile.get(id);
    while (!inFile.eof()) {
        s += arr[id]->code;
        //Saving decimal values of every 8-bit binary code
        while (s.length() > 8) {
            in += (char)binToDec(s.substr(0, 8));
            s = s.substr(8);
        }
        inFile.get(id);
    }

    //Finally if bits remaining are less than 8, append 0's
    int count = 8 - s.length();
	if (s.length() < 8) {
		s.append(count, '0');
	}
	in += (char)binToDec(s);
    //append count of appended 0's
    in += (char)count;

    //write the in string to the output file
	outFile.write(in.c_str(), in.size());
	inFile.close();
	outFile.close();
}

int main(){

    int t;  cin >> t;
    while( t-- ){
        int num;    cin >> num;

        string res = decToBin(num);
    }
    return 0;
}
