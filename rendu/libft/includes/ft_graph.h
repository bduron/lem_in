
#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# define MAXV 10000

typedef struct	s_edgenode
{
	int					y;
	int					weight;
	char				*name;
	struct s_edgenode	*next;

}				t_edgenode;

typedef struct	s_graph
{
	struct s_edgenode	*edges[MAXV + 1];
	int					degree[MAXV + 1];
	int					nvertices;
	int					nedges;
	t_bool				directed;
	int					bfs_parent[MAXV + 1];
	t_bool				bfs_processed[MAXV + 1];
	t_bool				bfs_discovered[MAXV + 1];


}				t_graph;


void initialize_graph(t_graph *g, t_bool directed);
void insert_edge(t_graph *g, int x, int y, t_bool directed);
void print_graph(t_graph *g, char **label);

void initialize_bfs(t_graph *g);
void bfs(t_graph *g, int start);
void process_vertex_late(int v);
void process_vertex_early(int v);
void process_edge(int v, int y);
void find_path_rec(int start, int end, int *parents);
t_list *find_path_bfs(int start, int end, int *parents);

#endif
