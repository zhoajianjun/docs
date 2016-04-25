"set nocompatible "去掉讨厌的有关vi一致性模式，避免以前版本的一些bug和局限
syntax on " 语法高亮
set   autoread " 设置当文件被改动时自动载入
set   autowrite "自动保存
set   backspace=indent,eol,start " 使回格键（backspace）正常处理indent, eol, start等
set nobackup "从不备份  
set autoindent "自动缩进，即每行的缩进值与上一行相等
set   cindent "使用 C 语言的缩进方式
set   cinoptions=:0 "C 语言缩进的具体方式
set   fileformat=unix
set   guioptions-=T " 隐藏工具栏
set   guioptions-=m " 隐藏菜单栏
set   guioptions-=r
set   guioptions-=l
set   helpheight=10 "initial height of the help window
set   helplang=cn
set   hidden " 允许在有未保存的修改时切换缓冲区，此时的修改由 vim 负责保存
set   history=100
set   hlsearch " 搜索时高亮显示被找到的文本
set   ignorecase smartcase " 搜索时忽略大小写，但在有一个或以上大写字母时仍保持对大小写敏感
set   incsearch " 输入搜索内容时就显示搜索结果
set   laststatus=2 " 显示状态栏 (默认值为 1, 无法显示状态栏)
set   mouse=a " 可以在buffer的任何地方使用鼠标（类似office中在工作区双击鼠标定位）,但是这样不能在vim中使用鼠标进行复制粘贴，但是可以使用y，p进行跨文件复制粘贴,如果使用set mouse=v,则可以在vim中使用鼠标进行复制粘贴，但在gvim中却无法使用鼠标进行定位。综合考虑还是使用set mouse=a
set   number
set   pumheight=10 "?
set   ruler " 打开状态栏标尺
set   scrolloff=5 " 光标移动到buffer的顶部和底部时保持5行距离
set   showcmd " 输入的命令显示出来，看的清楚些 
set   smartindent " 为C程序提供自动缩进
set   softtabstop=4 " 使得按退格键时可以一次删掉 4 个空格
set   textwidth=80 "80个字符宽度时候会自动换行
set   wildignore=*.bak,*.o,*.e,*~ "tab键的自动完成现在会忽略这些
set   wildmenu " 增强模式中的命令行自动完成操作
set   wildmode=list:longest,full
set wrap "设置自动换行 

"?
autocmd BufReadPost *
    \ if line("'\"") > 0 && line("'\"") <= line("$") |
    \     exe "normal g'\"" |
    \ endif

let mapleader=","
" Space to command mode.
nnoremap <space> :
vnoremap <space> :
" Switching between buffers.
nnoremap <C-h> <C-W>h
nnoremap <C-j> <C-W>j
nnoremap <C-k> <C-W>k
nnoremap <C-l> <C-W>l
inoremap <C-h> <Esc><C-W>h
inoremap <C-j> <Esc><C-W>j
inoremap <C-k> <Esc><C-W>k
inoremap <C-l> <Esc><C-W>l
" "cd" to change to open directory.
let OpenDir=system("pwd")
nmap <silent> <leader>cd :exe 'cd ' . OpenDir<cr>:pwd<cr>

" cscope.vim
if has("cscope")
    set csto=0 " 设置cstag命令查找次序：0先找cscope数据库再找标签文件；1先找标签文件再找cscope数据库
    set cst " 同时搜索cscope数据库和标签文件
    set nocsverb
    if filereadable("cscope.out")
        cs add cscope.out
    endif
    set csverb
    set cscopequickfix=s-,c-,d-,i-,t-,e-
    nmap <F5>s :cs find s <C-R>=expand("<cword>")<CR><CR>
    " 查找本定义
    nmap <F5>g :cs find g <C-R>=expand("<cword>")<CR><CR> 
    " 查找调用本函数的函数
    nmap <F5>c :cs find c <C-R>=expand("<cword>")<CR><CR>
    nmap <F5>t :cs find t <C-R>=expand("<cword>")<CR><CR>
    nmap <F5>e :cs find e <C-R>=expand("<cword>")<CR><CR>
    nmap <F5>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
    nmap <F5>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
    " 查找本函数调用的函数
    nmap <F5>d :cs find d <C-R>=expand("<cword>")<CR><CR>
endif

" VimGDB.vim
if has("gdb")
	set asm=0
	let g:vimgdb_debug_file=""
	run macros/gdb_mappings.vim
endif
" LookupFile setting
let g:LookupFile_TagExpr='"./tags.filename"'
let g:LookupFile_MinPatLength=2
let g:LookupFile_PreserveLastPattern=0
let g:LookupFile_PreservePatternHistory=1
let g:LookupFile_AlwaysAcceptFirst=1
let g:LookupFile_AllowNewFiles=0
" Man.vim
source $VIMRUNTIME/ftplugin/man.vim
" plugin shortcuts
function! RunShell(Msg, Shell)
	echo a:Msg . '...'
	call system(a:Shell)
	echon 'done'
endfunction

"add
set shiftwidth=4 " 设定 > 命令移动时的宽度为 4
let &termencoding=&encoding
set fileencodings=utf-8,gbk,ucs-bom,cp936
set formatoptions+=r

"tab键替换成4个空格
set et
set ci
set sw=4
set ts=4

"add right mouse
set mousemodel=popup

"adding taglist
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1

"add WinManager
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<cr>

"add font
set guifont=DejaVu\ Sans\ mono\ Italic\ 11 "字体 样式 字号

"add minibuf
let g:miniBufExplMapWindowNavVim = 1

"折叠功能
set foldmethod=syntax "按语法高亮进行折叠，za打开或关闭折叠
set foldlevel=100 " 启动 vim 时不要自动折叠代码

"全能补全
set completeopt=longest,menu "关掉智能补全时的预览窗口

"superTab,自动补全时用
let g:SuperTabRetainCompletionType=2
let g:SuperTabDefaultCompletionType="<C-X><C-O>"

"使用Bundle进行VIM插件的管理
set nocompatible              " be iMproved
filetype off                  " required!
set rtp+=~/.vim/bundle/vundle/
call vundle#rc()
" let Vundle manage Vundle
" required! 
Bundle 'gmarik/vundle'
" 可以通过以下四种方式指定插件的来源
" a) 指定Github中vim-scripts仓库中的插件，直接指定插件名称即可，插件明中的空格使用“-”代替。
"Bundle 'L9'
" b) 指定Github中其他用户仓库的插件，使用“用户名/插件名称”的方式指定
"Bundle 'tpope/vim-fugitive'
"Bundle 'Lokaltog/vim-easymotion'
"Bundle 'rstacruz/sparkup', {'rtp': 'vim/'}
"Bundle 'tpope/vim-rails.git'
" c) 指定非Github的Git仓库的插件，需要使用git地址
"Bundle 'git://git.wincent.com/command-t.git'
" d) 指定本地Git仓库中的插件
"Bundle 'file:///Users/gmarik/path/to/plugin'
filetype plugin indent on     " required!

"vim配色方法
Bundle 'morhetz/gruvbox'
colorscheme gruvbox
"set background=light   " Setting light mode
set background=dark   " Setting light mode
