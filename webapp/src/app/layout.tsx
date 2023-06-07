import './globals.css'
import { Inter } from 'next/font/google'
import Navbar from "@/components/UI/Navbar/Navbar";
import React from "react";

const inter = Inter({ subsets: ['latin'] })

export const metadata = {
  title: 'Booking cpp',
  description: 'Service for booking',
}

export default function RootLayout({
  children,
}: {
  children: React.ReactNode
}) {
  return (
    <html lang="en">
      <body className={inter.className}>
        {children}
      </body>
    </html>
  )
}
