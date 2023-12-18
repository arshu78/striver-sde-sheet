<h2><a href="https://leetcode.com/problems/vowels-of-all-substrings/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2063. Vowels of All Substrings</a></h2><h3>Medium</h3><hr><div><p>Given a string <code>word</code>, return <em>the <strong>sum of the number of vowels</strong> (</em><code>'a'</code>, <code>'e'</code><em>,</em> <code>'i'</code><em>,</em> <code>'o'</code><em>, and</em> <code>'u'</code><em>)</em> <em>in every substring of </em><code>word</code>.</p>

<p>A <strong>substring</strong> is a contiguous (non-empty) sequence of characters within a string.</p>

<p><strong>Note:</strong> Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> word = "aba"
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> word = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
- "a", "ab", and "abc" have 1 vowel each
- "b", "bc", and "c" have 0 vowels each
Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> word = "ltcd"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no vowels in any substring of "ltcd".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> consists of lowercase English letters.</li>
</ul>
</div>