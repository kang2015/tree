void InOrderTraverseBiTree(BiNode *root){
     stack s; BiNode *p = root;
     while(p||!s.empty()){
          if(p){s.push(p);p = p->left;}
          else{p = s.top(); visit(p); p.pop(); p= p->right;}
     }
}

void InOrderTraverseBiTree(BiNode *root){
     stack.push(root);
     while(!stack.empty()){
          treeNode p = stack.top();
          while(p){stack.push(p->left); p = p->left; }//left to null
          stack.pop();//pop null
          if(!stack.empty()){//visit p and step right 
               p = stack.top();
               visit(p);
               stack.pop();
               stack.push(p->right);
          }
     }
}
