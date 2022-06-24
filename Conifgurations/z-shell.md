
```
  apt search zsh

  sudo apt install zsh -y

  zsh --version
```

## install oh-my-zsh
- zsh & oh-my-zsh 的配置与使用(https://zhuanlan.zhihu.com/p/58073103)

```
  sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

The installer will rename ~/.zshrc to .zshrc.pre-oh-my-zsh

## add plugins into ~/zshrc

```
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting


plugins=(git osx zsh-autosuggestions zsh-syntax-highlighting)
```


## install powerlevel10k
```
```
config
```
  p10k configure
```