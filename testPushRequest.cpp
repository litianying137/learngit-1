Git 学习

受益匪浅
https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000

一、概念
1、Git 分布式版本控制系统，去中心化
2、stage 就是 index 文件目录结构的索引
3、git add命令实际上就是把要提交的所有修改放到暂存区（Stage），然后，执行git commit就可以一次性把暂存区的所有修改提交到分支。
4、你又理解了Git是如何跟踪修改的，每次修改，如果不add到暂存区，那就不会加入到commit中
5、$ ssh-keygen -t rsa -C "youremail@example.com" 生成ssh的私钥公钥
为什么GitHub需要SSH Key呢？因为GitHub需要识别出你推送的提交确实是你推送的，而不是别人冒充的，而Git支持SSH协议，所以，GitHub只要知道了你的公钥，就可以确认只有你自己才能推送。
6、分支管理
当我们创建新的分支，例如dev时，Git新建了一个指针叫dev，指向master相同的提交，再把HEAD指向dev，就表示当前分支在dev上：
因为创建、合并和删除分支非常快，所以Git鼓励你使用分支完成某个任务，合并后再删掉分支，这和直接在master分支上工作效果是一样的，但过程更安全。


二、实用命令
1、git init 创建git仓库
2、git add 添加文件列表 以空格分割文件名称 提交修改前也要add
3、git commit 把文件提交到仓库
4、git commit -m “提交注释信息”
5、git status 查看当前git仓库状态
6、git diff 查看未提交内容的修改
7、git log 查看提交记录 （作者、日期、备注）
8、git log --pretty=oneline 每条提交记录只显示一行
git log --graph --pretty=oneline --abbrev-commit 可以看到分支的合并情况
9、git reset --hard HEAD^ 回退版本 git reset --hard HEAD^100 （回退两个版本可以用HEAD^^ 或 HEAD^2）
10、git reset --hard 3628164 会滚到具体版本
11、git diff HEAD -- readme.txt 查看工作区和版本库里面最新版本的区别
12、git checkout -- readme.txt  可以丢弃工作区的修改,就是让这个文件回到最近一次git commit或git add时的状态
git checkout -- file命令中的--很重要，没有--，就变成了“切换到另一个分支”的命令
13、git rm 用于删除一个文件 删除后需要commit提交
14、git remote add origin github.com/litianying137/learnGit.git 本地git关联 gitHub仓库（提前在github上创建好仓库）
15、git remote rm origin 解除远程关联
16、git push origin master  把本地master分支的最新修改推送至GitHub，现在，你就拥有了真正的分布式版本库！
git push -u origin master第一次推送master分支的所有内容
17、git clone 命令克隆

分支管理
1、git checkout -b <name> 参数表示创建并切换分支
2、git branch 查看当前分支 与所有分支
3、git checkout master 切换到主分支
4、git merge <name>   合并某分支到当前分支

5、git branch -d <name> 删除分支
6、git branch <name> 创建新分支
7、git log --graph命令可以看到分支合并图
￼

管理：
stash 可以把当前工作现场“储藏”起来，等以后恢复现场后继续工作：处理当前分支位提交切换到其他分支的情况
git stash list 查看存储修改
一是用git stash apply恢复，但是恢复后，stash内容并不删除，你需要用git stash drop来删除；
另一种方式是用git stash pop，恢复的同时把stash内容也删了：
git stash apply stash@{0} 然后恢复指定的stash
如果要丢弃一个没有被合并过的分支，可以通过git branch -D <name>强行删除

多人协作：
1、git push origin master 推送分支，就是把该分支上的所有本地提交推送到远程库。推送时，要指定本地分支，这样，Git就会把该分支推送到远程库对应的远程分支上：
2、git remote 查看远程库的信息
git remote -v 查看更详细的信息
3、git pull 拉取分支信息
git pull origin master
如果git pull提示“no tracking information”，则说明本地分支和远程分支的链接关系没有创建，用命令git branch --set-upstream branch-name origin/branch-name。
这就是多人协作的工作模式，一旦熟悉了，就非常简单。

小结
* 查看远程库信息，使用git remote -v；

* 本地新建的分支如果不推送到远程，对其他人就是不可见的；
* git push --set-upstream origin feature1 之后可见

* 从本地推送分支，使用git push origin branch-name，如果推送失败，先用git pull抓取远程的新提交；

* 在本地创建和远程分支对应的分支，使用git checkout -b branch-name origin/branch-name，本地和远程分支的名称最好一致；

* 建立本地分支和远程分支的关联，使用git branch --set-upstream branch-name origin/branch-name；

* 从远程抓取分支，使用git pull，如果有冲突，要先处理冲突。


标签管理：
发布一个版本时，我们通常先在版本库中打一个标签（tag），这样，就唯一确定了打标签时刻的版本。将来无论什么时候，取某个标签的版本，就是把那个打标签的时刻的历史版本取出来。所以，标签也是版本库的一个快照。
1、git tag <name>用于新建一个标签，默认为HEAD，也可以指定一个commit id；
git tag v0.9 6224937 给制定的commit id打标签
git tag -a v0.1 -m "version 0.1 released" 3628164 -a指定标签名 -m添加标签说明内容
git tag -s v0.2 -m "signed version 0.2 released" fec145a 还可以通过-s用私钥签名一个标签

2、git tag查看所有标签
3、git show <tagname>查看标签信息
4、命令git push origin <tagname>可以推送一个本地标签；
5、命令git push origin --tags可以推送全部未推送过的本地标签
6、命令git tag -d <tagname>可以删除一个本地标签
7、命令git push origin :refs/tags/<tagname>可以删除一个远程标签。





