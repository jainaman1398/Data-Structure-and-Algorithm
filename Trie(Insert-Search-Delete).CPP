#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *children[27];
    bool isEndOfWord;
};

struct TrieNode *get_new(void)
{
    struct TrieNode *sample=new TrieNode();
    for(int i=0;i<26;i++)
        sample->children[i]=NULL;
    sample->isEndOfWord=false;

    return sample;
}

bool search_into(TrieNode *root,string key)
{
    struct TrieNode *aj=root;
    int logic=1;
    for(int i=0;i<key.size();i++)
    {
        int index=key[i]-'a';
        if(!aj->children[index])
        return false;
        aj=aj->children[index];
    }
    return(aj!=NULL&&aj->isEndOfWord);
}

void insert_into(TrieNode *root,string key)
{
    struct TrieNode *aj=root;
    for(int i=0;i<key.size();i++)
    {
        int index=key[i]-'a';
      if(!aj->children[index])
        aj->children[index]=get_new();

      aj=aj->children[index];
    }
    aj->isEndOfWord=true;
}

bool is_free(TrieNode *root)
{
    for(int i=0;i<26;i++)
        if(root->children[i])
        return 1;

    return 0;
}

bool delete_from(struct TrieNode* root,string key,int level,int len)
{
  if(root)
  {
    if(level==len)
    {
        root->isEndOfWord=false;
        if(is_free(root))
            return true;

        return false;
    }
    else
    {
        int index=key[level]-'a';
      if(delete_from(root->children[index],key,level+1,len))
      {
          free(root->children[index]);
          root->children[index]=NULL;
          return(is_free(root)&&root->isEndOfWord);
      }

    }
  }

  return false;
}

int main()
{
    string keys[]={"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their"};
     int n=sizeof(keys)/sizeof(keys[0]);
     TrieNode *root;
      root=get_new();
     for(int i=0;i<n;i++)
     {
         insert_into(root,keys[i]);
     }
     bool yo=search_into(root,"answer");
     cout<<yo;
     delete_from(root,"answer",0,5);
     yo=search_into(root,"answer");
     yo=search_into(root,"any");
     cout<<yo;
    return 0;
}
