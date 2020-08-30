1、基本数据结构
	1）、数组
	2）、链表
	3）、栈
	4）、队列，优先级队列，双端队列
	
2、基本数据结构
	1）、hash表，映射，集合
	2）、树
	3）、图
	
	
3、掌握基本算法模板（前3牢记，频次很高）
	1）、递归
	// C/C++
	void recursion(int level, int param) { 
		// recursion terminator
		if (level > MAX_LEVEL) { 
		// process result 
		return ; 
		}

		// process current logic 
		process(level, param);

		// drill down 
		recursion(level + 1, param);

		// reverse the current level status if needed
	}
	
	2）、DFS 和 BFS（记住分别对应栈和队列数据结构）
		void dfs(Node* root) {
			map<int, int> visited;
			if(!root) return ;

			stack<Node*> stackNode;
			stackNode.push(root);

			while (!stackNode.empty()) {
				Node* node = stackNode.top();
				stackNode.pop();
				if (visited.count(node->val)) continue;
				visited[node->val] = 1;


				for (int i = node->children.size() - 1; i >= 0; --i) {
					stackNode.push(node->children[i]);
				}
			}

			return ;
		}
		
		
		void bfs(Node* root) {
			map<int, int> visited;
			if(!root) return ;

			queue<Node*> queueNode;
			queueNode.push(root);

			while (!queueNode.empty()) {
				Node* node = queueNode.top();
				queueNode.pop();
				if (visited.count(node->val)) continue;
				visited[node->val] = 1;

				for (int i = 0; i < node->children.size(); ++i) {
				queueNode.push(node->children[i]);
				}
			}

			return ;
		}
		
		3）、二分查找
		int binarySearch(const vector<int>& nums, int target) {
			int left = 0, right = (int)nums.size()-1;
			
			while (left <= right) {
				int mid = left + (right - left)/ 2;
				if (nums[mid] == target) return mid;
				else if (nums[mid] < target) left = mid + 1;
				else right = mid - 1;
			}
			
			return -1;
		}
		
		4）、分治
		int divide_conquer(Problem *problem, int params) {
			// recursion terminator
			if (problem == nullptr) {
			process_result
			return return_result;
			} 

			// process current problem
			subproblems = split_problem(problem, data)
			subresult1 = divide_conquer(subproblem[0], p1)
			subresult2 = divide_conquer(subproblem[1], p1)
			subresult3 = divide_conquer(subproblem[2], p1)
			...

			// merge
			result = process_result(subresult1, subresult2, subresult3)
			// revert the current level status

			return 0;
		}
		
		5）Trie树
		class Trie {
			struct TrieNode {
				map<char, TrieNode*>child_table;
				int end;
				TrieNode(): end(0) {}
			};
				
			public:
				/** Initialize your data structure here. */
				Trie() {
					root = new TrieNode();
				}
				
				/** Inserts a word into the trie. */
				void insert(string word) {
					TrieNode *curr = root;
					for (int i = 0; i < word.size(); i++) {
						if (curr->child_table.count(word[i]) == 0)
							curr->child_table[word[i]] = new TrieNode();
							
						curr = curr->child_table[word[i]];                
					}
					curr->end = 1;
				}
				
				/** Returns if the word is in the trie. */
				bool search(string word) {
					return find(word, 1);
				}
				
				/** Returns if there is any word in the trie that starts with the given prefix. */
				bool startsWith(string prefix) {
					return find(prefix, 0);
				}
			private:
				TrieNode* root;
				bool find(string s, int exact_match) {
					TrieNode *curr = root;
					for (int i = 0; i < s.size(); i++) {
						if (curr->child_table.count(s[i]) == 0)
							return false;
						else
							curr = curr->child_table[s[i]];
					}
					
					if (exact_match)
						return (curr->end) ? true : false;
					else
						return true;
				}
		};
		
		6）、并查集
			class UnionFind {
				public:
					UnionFind(vector<vector<char>>& grid) {
						count = 0;
						int m = grid.size();
						int n = grid[0].size();
						for (int i = 0; i < m; ++i) {
							for (int j = 0; j < n; ++j) {
								if (grid[i][j] == '1') {
									parent.push_back(i * n + j);
									++count;
								}
								else {
									parent.push_back(-1);
								}
								rank.push_back(0);
							}
						}
					}

				//递归
					int find(int i) {
						if (parent[i] != i) {
							parent[i] = find(parent[i]);
						}
						return parent[i];
					}


					void unite(int x, int y) {
						int rootx = find(x);
						int rooty = find(y);
						if (rootx != rooty) {
							if (rank[rootx] < rank[rooty]) {
								swap(rootx, rooty);
							}
							parent[rooty] = rootx;
							if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
							--count;
						}
					}


					int getCount() const {
						return count;
					}


				private:
					vector<int> parent;
					vector<int> rank;
					int count;
				};
				
		
4、动态规划：
动态规划3个要素：
	1）、最优子结构
	2）、定义中间状态
	3）、根据中间状态，推导状态转移方程		
关键在于递推方程的推导，多练习，多用归纳法，多总结。


5、学习方法：
1、掌握基本套路，高频模板要背熟，大部分的题目都可以解决。
2、多练习，不死磕，学习其他人的好代码，为己所用，拿来主义。
