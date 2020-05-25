import networkx as nx
import matplotlib.pyplot as plt

G = nx.DiGraph()
G.add_edge('BTC', 'USD', weight=7800, title='BTC-USD', subtitle='testing')
G.add_edge('ETH', 'BTC', weight=1, title='ab', subtitle='testing')
G.add_edge('ETH', 'USD', weight=1, title='ab', subtitle='testing')
G.add_edge('LTC', 'BTC', weight=1, title='ab', subtitle='testing')
G.add_edge('LTC', 'USD', weight=1, title='ab', subtitle='testing')
G.add_edge('XRP', 'BTC', weight=1, title='ab', subtitle='testing')
G.add_edge('XRP', 'USD', weight=1, title='ab', subtitle='testing')
G.add_edge('BCH', 'BTC', weight=1, title='ab', subtitle='testing')
G.add_edge('BCH', 'USD', weight=1, title='ab', subtitle='testing')
G.add_edge('LINK', 'BTC', weight=1, title='ab', subtitle='testing')
G.add_edge('LINK', 'ETH', weight=1, title='ab', subtitle='testing')

edge_labels = nx.get_edge_attributes(G, 'weight')
print(edge_labels)

fig = plt.figure()
ax1 = plt.subplot2grid((1, 1), (0, 0))
#pos = nx.spring_layout(G)
pos = nx.circular_layout(G)
nx.draw(G, pos, edge_color='orange', with_labels=True)

nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, label_pos=0.5, font_size=10, font_color='black',
                             font_family='sans-serif', font_weight='normal', alpha=1.0, bbox=None, ax=None, rotate=True)
nx.draw_networkx_nodes(G=G, pos=pos, node_list=G.nodes(),
                       alpha=0.9, node_color='green', cmap='viridis')

plt.show()
