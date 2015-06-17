void InOrderTraverseBiTree(BiNode *root)
{
  if(root == NULL){
    return;
  }
  stack s;
  s.push(root);
  while(!s.empty()){
    BiNode *p = s.top();
    while(p->left) {s.push(p->left);p=p->left;}
    s.pop();
    visit(p);
    if(p->right!=NULL){
      s.push(p->right);
    }
  }
}
