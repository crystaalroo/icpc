
struct vertex {
  map<char,int> next,go;
  int p,link,exit;
  char pch;
  bool leaf;
  vertex(int p=-1, char pch=-1):p(p),pch(pch),exit(-2),link(-1),leaf(0){}
};

vector<vertex> t;
void aho_ini(){ t.clear();t.pb(vertex()); }
int add(string s, int id){
  int v=0;
  for(char c:s){
    if(!t[v].next.count(c)){
      t[v].next[c]=t.size();
      t.pb(vertex(v,c));
    }
    v=t[v].next[c];
  }
  t[v].leaf = 1;
  return v;
}
int go(int v, char c);
int get_link(int v){
  if(t[v].link<0)
    if(!v||!t[v].p)t[v].link=0;
    else t[v].link=go(get_link(t[v].p),t[v].pch);
  return t[v].link;
}
int go(int v, char c){
  if(!t[v].go.count(c))
    if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
    else t[v].go[c]=v==0?0:go(get_link(v),c);
  return t[v].go[c];
}
