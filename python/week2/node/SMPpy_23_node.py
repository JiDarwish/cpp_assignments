
class List:

    class Node:
        """ Een node bevat een value (val) en een next-ptr (lnk) """

        def __init__(self, val, lnk=None):
            self.val = val
            self.lnk = lnk

    def __init__(self):
        self.root = None

    def toon(self):
        """ returns a string containing de elements-value of list.
            The order is de order in the list, values are seperated buy ","
            and enclosed by "[" and "]".
            An example "[een,twee,zes]".
        """
        out = "["
        node = self.root
        sep = False
        while node != None:
            if sep: out += ", "
            if not sep: sep = True
            out += node.val 
            node = node.lnk
        out += "]"

        return out

    def append(self, val):
        """ Appends a node with value `val` to the end of the list.
        """
        node = self.root

        while node.lnk is not None:
            node = node.lnk

        node.lnk = self.Node(val)

    def insert(self, val):
        """ Inserts a node with value `val` to the beginning of the list.
        """
        node = self.Node(val, self.root)

        if self.root is None:
            self.root = node
            return

        self.root = node

    def addSorted(self, val):
        """ Add a node with value `val` to list.
            It's place is based on value `val`.
            All the items in de list are sorted on their value'
            An example: We have "[een,zes]"
            Adding "twee" will give "[een,twee,zes]"
            To work well the list must be in order.
        """
        node = self.root
        if node is None:
            node = self.Node(val)
            return

        nodeDaarna = node.lnk
        while nodeDaarna is not None:
            if node.val <= val <= nodeDaarna.val:
                node.lnk = self.Node(val, nodeDaarna)
                return
            node = node.lnk
            nodeDaarna = nodeDaarna.lnk

        node.lnk = self.Node(val)

    def delete(self, val):
        """ Verwijder the node with value `val` from the list.
        """

        node = self.root
        if node is None:
            raise Exception("List is empty!")

        if node.val == val:
            self.root = node.lnk
            return

        nodeDaarna = node.lnk

        while nodeDaarna is not None:
            if nodeDaarna.val == val:
                node.lnk = nodeDaarna.lnk
                return

            node = node.lnk
            nodeDaarna = nodeDaarna.lnk

        raise Exception("No such value available", val)


if __name__ == '__main__':
    lst = List()
    print(lst.toon())
    lst.insert("1")
    print(lst.toon())
    lst.insert("0")
    print(lst.toon())
    lst.addSorted("5")
    print(lst.toon())
    lst.addSorted("3")
    print(lst.toon())
    lst.addSorted("7")
    print(lst.toon())
    lst.addSorted("4")
    print(lst.toon())
    lst.append("8")
    print(lst.toon())
    lst.append("9")
    print(lst.toon())
    lst.addSorted("2")
    print(lst.toon())

    try:
        lst.delete("2")
        print(lst.toon())
        lst.delete("7")
        print(lst.toon())
        lst.delete("9")
        print(lst.toon())
        lst.delete("0")
        print(lst.toon())
        lst.delete("11")
        print(lst.toon())
    except Exception as e:
        print(e)
