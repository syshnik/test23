echo "# Test23" >> README.md
git init
git add README.md
git add --all
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/syshnik/Test23.git
git push -u origin main
pause