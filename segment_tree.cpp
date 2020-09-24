void build(int p, int l, int r) {
	if (l >= r)
		return;
	if (l + 1 == r) {
		t[p] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(2 * p + 1, l, m);
	build(2 * p + 2, m, r);
	t[p] = t[2 * p + 1] + t[2 * p + 2];
}
 
void update(int p, int l, int r, int pos, int value) {
	if (pos < l || pos >= r)
		return;
	if (l + 1 == r)
	{
		t[p] += value;
		return;
	}
	int m = (l + r) / 2;
	update(2 * p + 1, l, m, pos, value);
	update(2 * p + 2, m, r, pos, value);
	t[p] = t[2 * p + 1] + t[2 * p + 2];
}
 
long long get(int p, int l, int r, int a, int b) {
	if (a >= r || b <= l)
		return 0;
	if (a <= l && b >= r)
		return t[p];
	int m = (l + r) / 2;
	return (get(2 * p + 1, l, m, a, b) + get(2 * p + 2, m, r,a, b));
 
}
