using System;

namespace Treaap
{
    public class Treap
    {
        public int x;
        public int y;

        public Treap Left;
        public Treap Right;
        public Treap Parent;

        public Treap(int x, int y, Treap left = null, Treap right = null, Treap parent = null)
        {
            this.x = x;
            this.y = y;
            this.Left = left;
            this.Right = right;
            this.Parent = parent;
        }
        public void Split(int x, out Treap L, out Treap R)
        {
            Treap newTree = null;
            if (this.x <= x)
            {
                if (Right == null)
                    R = null;
                else
                    Right.Split(x, out newTree, out R);
                L = new Treap(this.x, y, Left, newTree);
            }
            else
            {
                if (Left == null)
                    L = null;
                else
                    Left.Split(x, out L, out newTree);
                R = new Treap(this.x, y, newTree, Right);
            }
        }

        public Treap Remove(int x)
        {
            Treap l, m, r;
            Split(x - 1, out l, out r);
            r.Split(x, out m, out r);
            return Merge(l, r);
        }

        public static Treap Merge(Treap L, Treap R)
        {
            if (L == null) return R;
            if (R == null) return L;

            if (L.y > R.y)
            {
                var newR = Merge(L.Right, R);
                return new Treap(L.x, L.y, L.Left, newR);
            }
            else
            {
                var newL = Merge(L, R.Left);
                return new Treap(R.x, R.y, newL, R.Right);
            }
        }


    }
}
