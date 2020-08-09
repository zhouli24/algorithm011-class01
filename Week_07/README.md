学习笔记

void bfs(Node* root, Node* begin, Node* end) {
  unorderd_set<Node *> visited, beginVisited, endVisited;
  if(!root) return ;

  beginVisited.insert(begin);
  endVisited.insert(end);

  while (!beginVisited.empty() && !endVisited.empty()) {
	if (beginVisited.size() > endVisited.size()) {
		unorderd_set<Node *> temp;
		temp = beginVisited;
		beginVisited = endVisited;
		endVisited = temp;
	}
	
	int num = beginVisited.size();
	unorderd_set<Node *> nextVisited ;
	for (Node *node ： beginVisited) {
		if (endVisited.count(node)) {
			/* 相遇，返回 */
			return；
		}
		
		if (visited.count(node)) continue;
		nextVisited.insert(node);
		visited.insert(node);
	}
	
	beginVisited = nextVisited;
  }

  return ;
}

学习笔记

void bfs(Node* root, Node* end) {
  unorderd_set<Node *> visited, beginVisited, endVisited;
  if(!root) return ;

  beginVisited.insert(root);
  endVisited.insert(end);

  while (!beginVisited.empty() && !endVisited.empty()) {
	if (beginVisited.size() > endVisited.size()) {
		unorderd_set<Node *> temp;
		temp = beginVisited;
		beginVisited = endVisited;
		endVisited = temp;
	}
	
	int num = beginVisited.size();
	unorderd_set<Node *> nextVisited ;
	for (Node *node ： beginVisited) {
		if (endVisited.count(node)) {
			/* 相遇，返回 */
			return；
		}
		
		if (visited.count(node)) continue;
		visited.insert(node);
		
		/* 插入无向图相邻节点，根据具体情况分析 */
		for (Nextnode : 相邻接点) {
			nextVisited.insert(nextNode)
		}
	}
	
	beginVisited = nextVisited;
  }

  return ;
}

