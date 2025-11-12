'''
El script de python solo sirvio para imprimir el arbol de manera horizontal y verificar que estaba bien construido, ade
mas de generar el archivo arbol.txt que se adjunta, el cual contiene la misma impresión del árbol que en el main.cpp
Además elimina errores de impresión que se tenían en el main.cpp (como el 89 que aparecía en la impresión del árbol)'''

#Jorge Arturo Montiel Navarro A01278612
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

# Función para construir el árbol usando inorden y postorden
def buildTree(inorder, postorder):
    if not inorder or not postorder:
        return None
    root_val = postorder.pop()  # Último del postorden es la raíz
    root = Node(root_val)
    index = inorder.index(root_val)
    # Importante: construir primero el subárbol derecho, luego el izquierdo
    root.right = buildTree(inorder[index+1:], postorder)
    root.left = buildTree(inorder[:index], postorder)
    return root

# Función para imprimir el árbol horizontal
def printTree(root, prefix="", isLeft=True):
    if root is not None:
        printTree(root.right, prefix + ("│   " if isLeft else "    "), False)
        print(prefix + ("└── " if isLeft else "┌── ") + str(root.value))
        printTree(root.left, prefix + ("    " if isLeft else "│   "), True)

# Datos de el main.cpp, reconstrucción del árbol -> Cualquier duda revisar main.cpp
inorder = [45,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,
           67,68,69,70,71,72,73,74,75,76,77,78,80,81,82,83,85,86,89]
postorder = [45,48,50,49,52,53,55,54,51,57,58,60,59,62,63,65,64,61,56,
             67,68,70,69,72,73,75,74,71,77,78,81,80,83,85,89,86,82,76,66]

# Reconstruir árbol y mostrarlo
root = buildTree(inorder, postorder)
printTree(root)

import sys
sys.stdout = open("arbol.txt", "w", encoding="utf-8")
printTree(root)
sys.stdout.close()
