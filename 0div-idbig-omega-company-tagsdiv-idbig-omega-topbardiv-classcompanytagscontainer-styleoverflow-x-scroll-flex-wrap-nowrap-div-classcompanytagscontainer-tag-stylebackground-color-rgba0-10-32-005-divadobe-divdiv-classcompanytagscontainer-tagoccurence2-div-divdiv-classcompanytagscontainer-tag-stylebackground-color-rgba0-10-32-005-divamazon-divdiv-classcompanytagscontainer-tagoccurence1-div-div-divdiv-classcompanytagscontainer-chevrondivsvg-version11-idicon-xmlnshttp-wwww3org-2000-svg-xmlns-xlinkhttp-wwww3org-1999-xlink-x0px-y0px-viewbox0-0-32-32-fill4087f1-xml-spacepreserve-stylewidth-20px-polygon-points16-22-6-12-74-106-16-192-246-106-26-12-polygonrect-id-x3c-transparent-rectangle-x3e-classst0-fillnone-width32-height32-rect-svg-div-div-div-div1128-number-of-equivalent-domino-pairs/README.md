<h2><a href="https://leetcode.com/problems/number-of-equivalent-domino-pairs/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Adobe</div><div class="companyTagsContainer--tagOccurence">2</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Amazon</div><div class="companyTagsContainer--tagOccurence">1</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1128. Number of Equivalent Domino Pairs</a></h2><h3>Easy</h3><hr><div><p>Given a list of <code>dominoes</code>, <code>dominoes[i] = [a, b]</code> is <strong>equivalent to</strong> <code>dominoes[j] = [c, d]</code> if and only if either (<code>a == c</code> and <code>b == d</code>), or (<code>a == d</code> and <code>b == c</code>) - that is, one domino can be rotated to be equal to another domino.</p>

<p>Return <em>the number of pairs </em><code>(i, j)</code><em> for which </em><code>0 &lt;= i &lt; j &lt; dominoes.length</code><em>, and </em><code>dominoes[i]</code><em> is <strong>equivalent to</strong> </em><code>dominoes[j]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> dominoes = [[1,2],[2,1],[3,4],[5,6]]
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= dominoes.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>dominoes[i].length == 2</code></li>
	<li><code>1 &lt;= dominoes[i][j] &lt;= 9</code></li>
</ul>
</div>