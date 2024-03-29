<h2><a href="https://leetcode.com/problems/camelcase-matching/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1023. Camelcase Matching</a></h2><h3>Medium</h3><hr><div><p>Given an array of strings <code>queries</code> and a string <code>pattern</code>, return a boolean array <code>answer</code> where <code>answer[i]</code> is <code>true</code> if <code>queries[i]</code> matches <code>pattern</code>, and <code>false</code> otherwise.</p>

<p>A query word <code>queries[i]</code> matches <code>pattern</code> if you can insert lowercase English letters pattern so that it equals the query. You may insert each character at any position and you may not insert any characters.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
<strong>Output:</strong> [true,false,true,true,false]
<strong>Explanation:</strong> "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
<strong>Output:</strong> [true,false,true,false,false]
<strong>Explanation:</strong> "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
<strong>Output:</strong> [false,true,false,false,false]
<strong>Explanation:</strong> "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length, queries.length &lt;= 100</code></li>
	<li><code>1 &lt;= queries[i].length &lt;= 100</code></li>
	<li><code>queries[i]</code> and <code>pattern</code> consist of English letters.</li>
</ul>
</div>