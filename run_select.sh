#!/bin/env sh

export TERMCAP="SC|screen.xterm-256color|VT 100/ANSI X3.64 virtual terminal::DO=\E[%dB:LE=\E[%dD:RI=\E[%dC:UP=\E[%dA:bs:bt=\E[Z::cd=\E[J:ce=\E[K:cl=\E[H\E[J:cm=\E[%i%d;%dH:ct=\E[3g::do=^J:nd=\E[C:pt:rc=\E8:rs=\Ec:sc=\E7:st=\EH:up=\EM::le=^H:bl=^G:cr=^M:it#8:ho=\E[H:nw=\EE:ta=^I:is=\E)0::li#49:co#166:am:xn:xv:LP:sr=\EM:al=\E[L:AL=\E[%dL::cs=\E[%i%d;%dr:dl=\E[M:DL=\E[%dM:dc=\E[P:DC=\E[%dP::im=\E[4h:ei=\E[4l:mi:IC=\E[%d@:ks=\E[?1h\E=::ke=\E[?1l\E>:vi=\E[?25l:ve=\E[34h\E[?25h:vs=\E[34l::ti=\E[?1049h:te=\E[?1049l:us=\E[4m:ue=\E[24m:so=\E[3m::se=\E[23m:mb=\E[5m:md=\E[1m:mh=\E[2m:mr=\E[7m::me=\E[m:ms::Co#8:pa#64:AF=\E[3%dm:AB=\E[4%dm:op=\E[39;49m:AX::vb=\Eg:G0:as=\E(0:ae=\E(B::ac=\140\140aaffggjjkkllmmnnooppqqrrssttuuvvwwxxyyzz{{||}}~~..--++,,hhII00::po=\E[5i:pf=\E[4i:Km=\E[<:k0=\E[10~:k1=\EOP:k2=\EOQ::k3=\EOR:k4=\EOS:k5=\E[15~:k6=\E[17~:k7=\E[18~::k8=\E[19~:k9=\E[20~:k;=\E[21~:F1=\E[23~:F2=\E[24~::F3=\E[1;2P:F4=\E[1;2Q:F5=\E[1;2R:F6=\E[1;2S::F7=\E[15;2~:F8=\E[17;2~:F9=\E[18;2~:FA=\E[19;2~::FB=\E[20;2~:FC=\E[21;2~:FD=\E[23;2~:FE=\E[24;2~:kb=^H::K2=\EOE:kB=\E[Z:kF=\E[1;2B:kR=\E[1;2A:*4=\E[3;2~::*7=\E[1;2F:#2=\E[1;2H:#3=\E[2;2~:#4=\E[1;2D:%c=\E[6;2~::%e=\E[5;2~:%i=\E[1;2C:kh=\E[1~:@1=\E[1~:kH=\E[4~::@7=\E[4~:kN=\E[6~:kP=\E[5~:kI=\E[2~:kD=\E[3~:ku=\EOA::kd=\EOB:kr=\EOC:kl=\EOD:km:"

$@
